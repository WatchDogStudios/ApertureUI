#include <APCore/Interfaces/APCPlatform.h>

#include <APCore/APEngine.h>

bool aperture::core::IAPCPlatform::InitializePlatform(const char* licensekey)
{
  // NOTE(Mikael A.): Removing All CryptoLens API calls for FOSS release.
  // TODO: #1: Implement Resources Check(https://github.com/WatchDogStudios/ApertureUI/issues/1).
  aperture::ApertureSDK::SetSDKActive(true);
  m_bEngineStatus = true;
  return true;
}

void aperture::core::IAPCPlatform::SetFileSystem(const IAPCFileSystem& in_filesystem)
{
  NS_LOCK(lockermt);
  m_filesystem = const_cast<IAPCFileSystem*>(&in_filesystem);
}

void aperture::core::IAPCPlatform::SetMemoryAllocator(const IAPCMemoryAllocator& in_memorysystem)
{
  NS_LOCK(lockermt);
  m_memoryallocator = const_cast<IAPCMemoryAllocator*>(&in_memorysystem);
}

void aperture::core::IAPCPlatform::SetLoggingSystem(const IAPCLoggingSystem& in_loggingsystem)
{
  if (&in_loggingsystem)
  {
    NS_LOCK(lockermt);
    m_loggingsystem = const_cast<IAPCLoggingSystem*>(&in_loggingsystem);
  }
}

bool aperture::core::IAPCPlatform::IsEngineReady()
{
  return m_bEngineStatus;
}


