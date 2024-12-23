#include <Foundation/FoundationPCH.h>
#include <Foundation/Memory/Allocator.h>

void* nsAllocator::Reallocate(void* pPtr, size_t uiCurrentSize, size_t uiNewSize, size_t uiAlign)
{
  void* pNewMem = Allocate(uiNewSize, uiAlign);
  memcpy(pNewMem, pPtr, uiCurrentSize);
  Deallocate(pPtr);
  return pNewMem;
}
