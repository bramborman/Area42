﻿using System;
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
        private int windowCount = 0;

        public App()
        {
            InitializeComponent();
            Suspending += OnSuspending;
        }

        protected override async void OnLaunched(LaunchActivatedEventArgs e)
        {
            if (e.PreviousExecutionState == ApplicationExecutionState.Running)
            {
                CoreApplicationView newView = CoreApplication.CreateNewView();
                int newViewId = 0;

                await newView.Dispatcher.RunAsync(CoreDispatcherPriority.Normal, () =>
                {
                    Frame frame = new Frame();
                    Window.Current.Content = frame;

                    frame.RequestedTheme = AppData.Current.Theme;

                    frame.Navigate(typeof(MainPage), new MainPage.NavigationParameters(null, ++windowCount));
                    Window.Current.Activate();

                    newViewId = ApplicationView.GetForCurrentView().Id;
                    BarsHelper.Current.InitializeForCurrentAdditionalView();
                });
                
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
            
            rootFrame.RequestedTheme = AppData.Current.Theme;
            BarsHelper.Current.InitializeForCurrentView(BarsHelperColorMode.Themed, () => AppData.Current.Theme, AppData.Current, nameof(AppData.Theme));

            if (!e.PrelaunchActivated)
            {
                if (rootFrame.Content == null)
                {
                    rootFrame.Navigate(typeof(MainPage), new MainPage.NavigationParameters(e.Arguments, ++windowCount));
                }

                Window.Current.Activate();
            }
        }
        
        private void OnNavigationFailed(object sender, NavigationFailedEventArgs e)
        {
            throw new Exception("Failed to load Page " + e.SourcePageType.FullName);
        }
        
        private void OnSuspending(object sender, SuspendingEventArgs e)
        {
            SuspendingDeferral deferral = e.SuspendingOperation.GetDeferral();
            deferral.Complete();
        }
    }
}
