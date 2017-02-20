using System;
using UWPHelper.Utilities;
using Windows.ApplicationModel;
using Windows.ApplicationModel.Activation;
using Windows.ApplicationModel.Core;
using Windows.UI.Core;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace MoreViewsTest
{
    public sealed partial class App : Application
    {
        public App()
        {
            InitializeComponent();
            Suspending += OnSuspending;
        }

        protected override async void OnActivated(IActivatedEventArgs args)
        {
            if (args.PreviousExecutionState == ApplicationExecutionState.Running)
            {
                CoreApplicationView newView = CoreApplication.CreateNewView();
                int newViewId = 0;

                await newView.Dispatcher.RunAsync(CoreDispatcherPriority.Normal, () =>
                {
                    Frame frame = new Frame();
                    Window.Current.Content = frame;

                    frame.RequestedTheme = AppData.Current.Theme;

                    frame.Navigate(typeof(MainPage));
                    Window.Current.Activate();

                    newViewId = ApplicationView.GetForCurrentView().Id;
                    BarsHelper.Current.InitializeForCurrentAdditionalView();
                });

                //TODO: Close another views when main view is closed since after that new view cannot be displayed
                await ApplicationViewSwitcher.TryShowAsStandaloneAsync(newViewId);
                return;
            }

            Frame rootFrame = Window.Current.Content as Frame;

            if (rootFrame == null)
            {
                rootFrame = new Frame();
                rootFrame.NavigationFailed += OnNavigationFailed;

                Window.Current.Content = rootFrame;
            }
            
            LaunchActivatedEventArgs launchArgs = args as LaunchActivatedEventArgs;
            rootFrame.RequestedTheme = AppData.Current.Theme;
            BarsHelper.Current.InitializeForCurrentView(BarsHelperColorMode.Themed, () => AppData.Current.Theme, AppData.Current, nameof(AppData.Theme));

            if (launchArgs?.PrelaunchActivated != true)
            {
                if (rootFrame.Content == null)
                {
                    rootFrame.Navigate(typeof(MainPage), launchArgs?.Arguments);
                }

                Window.Current.Activate();
            }
        }

        protected override void OnLaunched(LaunchActivatedEventArgs e)
        {
            OnActivated(e);
        }

        private void OnNavigationFailed(object sender, NavigationFailedEventArgs e)
        {
            throw new Exception("Failed to load Page " + e.SourcePageType.FullName);
        }
        
        private void OnSuspending(object sender, SuspendingEventArgs e)
        {
            var deferral = e.SuspendingOperation.GetDeferral();
            deferral.Complete();
        }
    }
}
