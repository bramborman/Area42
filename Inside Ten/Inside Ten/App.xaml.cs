using System;
using System.Threading.Tasks;
using Windows.ApplicationModel;
using Windows.ApplicationModel.Activation;
using Windows.Foundation;
using Windows.Foundation.Metadata;
using Windows.UI;
using Windows.UI.Core;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace InsideTen
{
    sealed partial class App : Application
    {
        public App()
        {
            InitializeComponent();
            Suspending += OnSuspending;
        }

        private static Color MixColors(Color first, Color second)
        {
            int r = first.R * first.A + second.R * second.A;
            int g = first.G * first.A + second.G * second.A;
            int b = first.B * first.A + second.B * second.A;

            return Color.FromArgb(0xff, (byte)r, (byte)g, (byte)b);
        }
        
        public void SetBarsColors()
        {
            if (ApiInformation.IsTypePresent("Windows.UI.ViewManagement.ApplicationView"))
            {
                ApplicationViewTitleBar titleBar = ApplicationView.GetForCurrentView().TitleBar;

                if (titleBar != null)
                {
                    Color accentColor = (Color)Resources["SystemAccentColor"];

                    titleBar.BackgroundColor = accentColor;
                    titleBar.ForegroundColor = Colors.White;
                    titleBar.InactiveForegroundColor = Color.FromArgb(0xFF, 0x66, 0x66, 0x66);

                    titleBar.ButtonHoverBackgroundColor     = Color.FromArgb(0xFF, 0x19, 0x19, 0x19);
                    titleBar.ButtonInactiveForegroundColor  = Color.FromArgb(0xFF, 0x66, 0x66, 0x66);
                    titleBar.ButtonPressedBackgroundColor   = Color.FromArgb(0xFF, 0x33, 0x33, 0x33);
                    
                    titleBar.InactiveBackgroundColor = titleBar.BackgroundColor;

                    titleBar.ButtonBackgroundColor = titleBar.BackgroundColor;
                    titleBar.ButtonForegroundColor = titleBar.ForegroundColor;

                    titleBar.ButtonHoverForegroundColor     = titleBar.ButtonForegroundColor;
                    titleBar.ButtonInactiveBackgroundColor  = titleBar.InactiveBackgroundColor;
                    titleBar.ButtonPressedForegroundColor   = titleBar.ButtonForegroundColor;
                }
            }

            if (ApiInformation.IsTypePresent("Windows.UI.ViewManagement.StatusBar"))
            {
                StatusBar statusBar = StatusBar.GetForCurrentView();

                if (statusBar != null)
                {
                    statusBar.BackgroundOpacity = 1;

                    statusBar.BackgroundColor = (Color)Resources["SystemAccentColor"];
                    statusBar.ForegroundColor = Color.FromArgb(0xFF, 0xC7, 0xC7, 0xC7);
                }
            }
        }

        private async void Initialize(IActivatedEventArgs args)
        {
            bool loadAppData = AppData.Current == null;
            Task loadAppDataTask = null;

            if (loadAppData)
            {
                loadAppDataTask = AppData.LoadAsync();
            }
            
            Frame rootFrame = Window.Current.Content as Frame;

            if (rootFrame == null)
            {
                rootFrame = new Frame();
                rootFrame.NavigationFailed += OnNavigationFailed;
                
                Window.Current.Content = rootFrame;

                if (ApiInformation.IsTypePresent("Windows.UI.ViewManagement.ApplicationView"))
                {
                    ApplicationView.GetForCurrentView().SetPreferredMinSize(new Size(330, 460));
                }

                SetBarsColors();
                Window.Current.Activated += (sender, e) =>
                {
                    if (e.WindowActivationState != CoreWindowActivationState.Deactivated)
                    {
                        SetBarsColors();
                    }
                };
            }
            
            LaunchActivatedEventArgs launchArgs = args as LaunchActivatedEventArgs;

            if (loadAppData)
            {
                await loadAppDataTask;
            }

            if (launchArgs?.PrelaunchActivated != true)
            {
                if (rootFrame.Content == null)
                {
                    rootFrame.Navigate(typeof(MainPage), launchArgs?.Arguments);
                }

                Window.Current.Activate();
            }
        }

        protected override void OnActivated(IActivatedEventArgs args)
        {
            Initialize(args);
        }

        protected override void OnLaunched(LaunchActivatedEventArgs e)
        {
            Initialize(e);
        }

        private void OnNavigationFailed(object sender, NavigationFailedEventArgs e)
        {
            throw new Exception("Failed to load Page " + e.SourcePageType.FullName);
        }

        private async void OnSuspending(object sender, SuspendingEventArgs e)
        {
            var deferral = e.SuspendingOperation.GetDeferral();

            await AppData.Current?.SaveAsync();
            deferral.Complete();
        }
    }
}