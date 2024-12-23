#pragma once

#include <Foundation/Basics.h>

#include <Foundation/Utilities/EnumerableClass.h>

class NS_FOUNDATION_DLL nsPlatformDesc : public nsEnumerable<nsPlatformDesc>
{
  NS_DECLARE_ENUMERABLE_CLASS(nsPlatformDesc);

public:
  nsPlatformDesc(const char* szName, const char* szType)
  {
    m_szName = szName;
    m_szType = szType;
  }

  const char* GetName() const
  {
    return m_szName;
  }

  const char* GetType() const
  {
    return m_szType;
  }

  static const nsPlatformDesc& GetThisPlatformDesc()
  {
    return *s_pThisPlatform;
  }

private:
  static const nsPlatformDesc* s_pThisPlatform;

  const char* m_szName;
  const char* m_szType;
};
