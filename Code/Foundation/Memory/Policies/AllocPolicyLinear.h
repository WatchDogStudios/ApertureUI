#pragma once

#include <Foundation/Containers/HybridArray.h>

/// \brief This policy implements a linear allocator that can only grow and at some point all allocations gets reset at once.
///
/// For debugging purposes, the policy can also overwrite all freed memory with 0xCDCDCDCD to make it easier to find use-after-free situations.
///
/// \see nsAllocatorWithPolicy
template <bool OverwriteMemoryOnReset = false>
class nsAllocPolicyLinear
{
public:
  enum
  {
    Alignment = 16
  };

  NS_FORCE_INLINE nsAllocPolicyLinear(nsAllocator* pParent)
    : m_pParent(pParent)
    , m_uiNextBucketSize(4096)
  {
  }

  NS_FORCE_INLINE ~nsAllocPolicyLinear()
  {
    NS_ASSERT_DEV(m_uiCurrentBucketIndex == 0 && (m_Buckets.IsEmpty() || m_Buckets[m_uiCurrentBucketIndex].GetPtr() == m_pNextAllocation),
      "There is still something allocated!");
    for (auto& bucket : m_Buckets)
    {
      m_pParent->Deallocate(bucket.GetPtr());
    }
  }

  NS_FORCE_INLINE void* Allocate(size_t uiSize, size_t uiAlign)
  {
    NS_IGNORE_UNUSED(uiAlign);
    NS_ASSERT_DEV(uiAlign <= Alignment && Alignment % uiAlign == 0, "Unsupported alignment {0}", ((nsUInt32)uiAlign));
    uiSize = nsMemoryUtils::AlignSize(uiSize, (size_t)Alignment);

    bool bFoundBucket = !m_Buckets.IsEmpty() && m_pNextAllocation + uiSize <= m_Buckets[m_uiCurrentBucketIndex].GetEndPtr();

    if (!bFoundBucket)
    {
      // Check if there is an empty bucket that fits the allocation
      for (nsUInt32 i = m_uiCurrentBucketIndex + 1; i < m_Buckets.GetCount(); ++i)
      {
        auto& testBucket = m_Buckets[i];
        if (uiSize <= testBucket.GetCount())
        {
          m_uiCurrentBucketIndex = i;
          m_pNextAllocation = testBucket.GetPtr();
          bFoundBucket = true;
          break;
        }
      }
    }

    if (!bFoundBucket)
    {
      while (uiSize > m_uiNextBucketSize)
      {
        NS_ASSERT_DEBUG(m_uiNextBucketSize > 0, "");

        m_uiNextBucketSize *= 2;
      }

      m_uiCurrentBucketIndex = m_Buckets.GetCount();

      auto newBucket = nsArrayPtr<nsUInt8>(static_cast<nsUInt8*>(m_pParent->Allocate(m_uiNextBucketSize, Alignment)), m_uiNextBucketSize);
      m_Buckets.PushBack(newBucket);

      m_pNextAllocation = newBucket.GetPtr();

      m_uiNextBucketSize *= 2;
    }

    NS_ASSERT_DEBUG(m_pNextAllocation + uiSize <= m_Buckets[m_uiCurrentBucketIndex].GetEndPtr(), "");

    nsUInt8* ptr = m_pNextAllocation;
    m_pNextAllocation += uiSize;
    return ptr;
  }

  NS_FORCE_INLINE void Deallocate(void* pPtr)
  {
    NS_IGNORE_UNUSED(pPtr);
    // Individual deallocation is not supported by this allocator
  }

  NS_FORCE_INLINE void Reset()
  {
    m_uiCurrentBucketIndex = 0;
    m_pNextAllocation = !m_Buckets.IsEmpty() ? m_Buckets[0].GetPtr() : nullptr;

    if constexpr (OverwriteMemoryOnReset)
    {
      for (auto& bucket : m_Buckets)
      {
        nsMemoryUtils::PatternFill(bucket.GetPtr(), 0xCD, bucket.GetCount());
      }
    }
  }

  NS_FORCE_INLINE void FillStats(nsAllocator::Stats& ref_stats)
  {
    ref_stats.m_uiNumAllocations = m_Buckets.GetCount();
    for (auto& bucket : m_Buckets)
    {
      ref_stats.m_uiAllocationSize += bucket.GetCount();
    }
  }

  NS_ALWAYS_INLINE nsAllocator* GetParent() const { return m_pParent; }

private:
  nsAllocator* m_pParent = nullptr;

  nsUInt32 m_uiCurrentBucketIndex = 0;
  nsUInt32 m_uiNextBucketSize = 0;

  nsUInt8* m_pNextAllocation = nullptr;

  nsHybridArray<nsArrayPtr<nsUInt8>, 4> m_Buckets;
};
