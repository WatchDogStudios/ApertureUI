#include <Foundation/FoundationPCH.h>

#if NS_ENABLED(NS_PLATFORM_WINDOWS_UWP)
#  include <Foundation/Application/Application.h>
#  include <Foundation/IO/OSFile.h>
#  include <Foundation/Platform/UWP/Application_UWP.h>
#  include <Foundation/Platform/Win/Utils/IncludeWindows.h>
#  include <Foundation/Strings/StringConversion.h>

// Disable warning produced by CppWinRT
#  pragma warning(disable : 5205)
#  include <winrt/Windows.ApplicationModel.Activation.h>
#  include <winrt/Windows.ApplicationModel.Core.h>
#  include <winrt/Windows.Foundation.Collections.h>
#  include <winrt/Windows.Foundation.h>
#  include <winrt/Windows.UI.Core.h>

using namespace winrt::Windows::ApplicationModel::Core;

nsUwpApplication::nsUwpApplication(nsApplication* application)
  : m_application(application)
{
}

nsUwpApplication::~nsUwpApplication() {}

winrt::Windows::ApplicationModel::Core::IFrameworkView nsUwpApplication::CreateView()
{
  return this->get_strong().try_as<winrt::Windows::ApplicationModel::Core::IFrameworkView>();
}

void nsUwpApplication::Initialize(winrt::Windows::ApplicationModel::Core::CoreApplicationView const& applicationView)
{
  applicationView.Activated({this, &nsUwpApplication::OnViewActivated});
}

void nsUwpApplication::SetWindow(winrt::Windows::UI::Core::CoreWindow const& window)
{
  NS_IGNORE_UNUSED(window);
}

void nsUwpApplication::Load(winrt::hstring const& entryPoint)
{
  NS_IGNORE_UNUSED(entryPoint);
}

void nsUwpApplication::Run()
{
  if (nsRun_Startup(m_application).Succeeded())
  {
    auto window = winrt::Windows::UI::Core::CoreWindow::GetForCurrentThread();
    window.Activate();

    nsRun_MainLoop(m_application);
  }
  nsRun_Shutdown(m_application);
}

void nsUwpApplication::Uninitialize()
{
}

void nsUwpApplication::OnViewActivated(winrt::Windows::ApplicationModel::Core::CoreApplicationView const& sender, winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs const& args)
{
  sender.Activated(m_activateRegistrationToken);

  if (args.Kind() == winrt::Windows::ApplicationModel::Activation::ActivationKind::Launch)
  {
    auto launchArgs = args.as<winrt::Windows::ApplicationModel::Activation::LaunchActivatedEventArgs>();
    winrt::hstring argHString = launchArgs.Arguments();

    nsDynamicArray<const char*> argv;
    nsCommandLineUtils::SplitCommandLineString(nsStringUtf8(argHString.c_str()).GetData(), true, m_commandLineArgs, argv);

    m_application->SetCommandLineArguments(argv.GetCount(), argv.GetData());
  }
}

NS_FOUNDATION_DLL nsResult nsUWPRun(nsApplication* pApp)
{
  {
    auto application = winrt::make<nsUwpApplication>(pApp);
    winrt::Windows::ApplicationModel::Core::CoreApplication::Run(application.as<winrt::Windows::ApplicationModel::Core::IFrameworkViewSource>());
  }

  return NS_SUCCESS;
}

#endif
