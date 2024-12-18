#pragma warning(push)
#pragma warning(disable : 4091)
/*
This code is part of Aperture UI - A HTML/CSS/JS UI Middleware

Copyright (c) 2020-2024 WD Studios L.L.C. and/or its licensors. All
rights reserved in all media.

The coded instructions, statements, computer programs, and/or related
material (collectively the "Data") in these files contain confidential
and unpublished information proprietary WD Studios and/or its
licensors, which is protected by United States of America federal
copyright law and by international treaties.

This software or source code is supplied under the terms of a license
agreement and nondisclosure agreement with WD Studios L.L.C. and may
not be copied, disclosed, or exploited except in accordance with the
terms of that agreement. The Data may not be disclosed or distributed to
third parties, in whole or in part, without the prior written consent of
WD Studios L.L.C..

WD STUDIOS MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS
SOURCE CODE FOR ANY PURPOSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER, ITS AFFILIATES,
PARENT COMPANIES, LICENSORS, SUPPLIERS, OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OR PERFORMANCE OF THIS SOFTWARE OR SOURCE CODE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include <APCore/COREAPEngineDLL.h>
#include <APCore/Interfaces/APCPlatform.h>
#include <APHTML/APEngineCommonIncludes.h>
namespace aperture::core
{
  class IAPCCommand;
}
namespace aperture
{
  /// @brief Static Interface for setting global values for the Aperture SDK.
  /// @warning This class is not meant for initialization, but for setting global values. please set values before using the SDK.
  static class NS_COREAPENGINE_DLL ApertureSDK
  {
  public:
    // @note We scope lock write access to these values for protection.
    // @note Also, we do not allow for the values to be changed after the SDK is active.
    static NS_ALWAYS_INLINE void SetScriptThreadCount(nsUInt8 p_threadcount)
    {
      if (IsSDKActive())
      {
        nsLog::SeriousWarning("ApertureSDK: Cannot change the amount of Script Threads after the SDK has been initialized.");
        return;
      }
      {
        NS_LOCK(m_SDKLocker);
        m_pScriptThreadCount = p_threadcount;
      }
    }
    static NS_ALWAYS_INLINE nsUInt8 GetScriptThreadCount()
    {
      return m_pScriptThreadCount;
    }
    static NS_ALWAYS_INLINE void SetRenderThreadCount(nsUInt8 p_threadcount)
    {
      if (IsSDKActive())
      {
        nsLog::SeriousWarning("ApertureSDK: Cannot change the amount of Render Threads after the SDK has been initialized.");
        return;
      }
      {
        NS_LOCK(m_SDKLocker);
        m_pRenderThreadCount = p_threadcount;
      }
    }
    static NS_ALWAYS_INLINE nsUInt8 GetRenderThreadCount()
    {
      return m_pRenderThreadCount;
    }
    static NS_ALWAYS_INLINE void SetCompositionThreadCount(nsUInt8 p_threadcount)
    {
      if (IsSDKActive())
      {
        nsLog::SeriousWarning("ApertureSDK: Cannot change the amount of Composition Threads after the SDK has been initialized.");
        return;
      }
      {
        NS_LOCK(m_SDKLocker);
        m_pCompositionThreadCount = p_threadcount;
      }
    }
    static NS_ALWAYS_INLINE nsUInt8 GetCompositionThreadCount()
    {
      return m_pCompositionThreadCount;
    }
    static NS_ALWAYS_INLINE void SetPlatformName(const nsString& p_platformname)
    {
      if (IsSDKActive())
      {
        nsLog::SeriousWarning("ApertureSDK: Cannot change the Platform Name after the SDK has been initialized.");
        return;
      }
      {
        NS_LOCK(m_SDKLocker);
        m_sPlatformName = p_platformname;
      }
    }
    static NS_ALWAYS_INLINE nsString GetPlatformName()
    {
      return m_sPlatformName;
    }
    static NS_ALWAYS_INLINE void SetPlatformVersion(const nsString& p_platformversion)
    {
      if (IsSDKActive())
      {
        nsLog::SeriousWarning("ApertureSDK: Cannot change the Platform Version after the SDK has been initialized.");
        return;
      }
      {
        NS_LOCK(m_SDKLocker);
        m_sPlatformVersion = p_platformversion;
      }
    }
    static NS_ALWAYS_INLINE nsString GetPlatformVersion()
    {
      return m_sPlatformVersion;
    }
    static NS_ALWAYS_INLINE bool IsSDKActive()
    {
      return m_bSDKActive;
    }
    static void SetSDKActive(bool p_active);

  private:
    /// @brief Sets the amount of threads that aperture can create/use for Script Compiling/Execution.
    static inline nsUInt8 m_pScriptThreadCount;
    /// @brief Sets the amount of threads that aperture can create/use for Rendering.
    static inline nsUInt8 m_pRenderThreadCount;
    /// @brief Sets the amount of threads that aperture can create/use for Composition (HTML, DOM, CSS, etc).
    static inline nsUInt8 m_pCompositionThreadCount;
    /// @brief The Name of the current platform that the SDK is running on.
    static inline nsString m_sPlatformName;
    /// @brief The Version of the current platform that the SDK is running on.
    /// @note This is not the version of the SDK, but the version of the platform that the SDK is running on.
    static inline nsString m_sPlatformVersion;
    /// @brief The Version of the SDK that is currently being used.
    static inline nsString m_sSDKVersion;
    /// @brief Is the SDK Active? (Has it been initialized?)
    /// @note This would be set by the APCPlatform on initialization.
    static inline bool m_bSDKActive;
    /// @brief Are We in Trial Mode?
    /// @note This is used to determine if the SDK is in Trial Mode. This should ONLY be used for feedback to the user about their license. the SDK should never use the value outside of that.
    static inline bool m_bSDKTrial;
    static inline nsMutex m_SDKLocker;
  };
} // namespace aperture
