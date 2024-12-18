#pragma once

#if NS_ENABLED(NS_PLATFORM_WINDOWS_UWP)

#  include <Foundation/Platform/UWP/Utils/UWPUtils.h>
#  include <Windows.ApplicationModel.ExtendedExecution.h>
#  include <Windows.ApplicationModel.core.h>
#  include <Windows.Applicationmodel.h>

using namespace ABI::Windows::ApplicationModel::Core;
using namespace ABI::Windows::ApplicationModel::Activation;
using namespace ABI::Windows::ApplicationModel::ExtendedExecution;

class nsTestFramework;

class nsUwpTestApplication : public RuntimeClass<IFrameworkViewSource, IFrameworkView>
{
public:
  nsUwpTestApplication(nsTestFramework& testFramework);
  virtual ~nsUwpTestApplication();

  // Inherited via IFrameworkViewSource
  virtual HRESULT __stdcall CreateView(IFrameworkView** viewProvider) override;

  // Inherited via IFrameworkView
  virtual HRESULT __stdcall Initialize(ICoreApplicationView* applicationView) override;
  virtual HRESULT __stdcall SetWindow(ABI::Windows::UI::Core::ICoreWindow* window) override;
  virtual HRESULT __stdcall Load(HSTRING entryPoint) override;
  virtual HRESULT __stdcall Run() override;
  virtual HRESULT __stdcall Uninitialize() override;

private:
  // Events
  HRESULT OnActivated(ICoreApplicationView* applicationView, IActivatedEventArgs* args);
  HRESULT OnSessionRevoked(IInspectable* sender, IExtendedExecutionRevokedEventArgs* args);

  nsTestFramework& m_testFramework;
  EventRegistrationToken m_eventRegistrationOnActivate;
  EventRegistrationToken m_eventRegistrationOnRevokedSession;
  ComPtr<IExtendedExecutionSession> m_extendedExecutionSession;
};

#endif
