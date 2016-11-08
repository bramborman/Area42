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
    public sealed partial class App : Application
    {
        Color? lastAccentColor;
        Frame rootFrame;
        SystemNavigationManager systemNavigationManager;

        public App()
        {
            InitializeComponent();
            Suspending += OnSuspending;
        }
        
        private Color? MixColors(Color? first, Color? second)
        {
            if (first == null || second == null)
            {
                return null;
            }

            byte r = (byte)Math.Min(first.Value.R + second.Value.R, 0xFF);
            byte g = (byte)Math.Min(first.Value.G + second.Value.G, 0xFF);
            byte b = (byte)Math.Min(first.Value.B + second.Value.B, 0xFF);

            return Color.FromArgb(0xFF, r, g, b);
        }
        
        public void SetBarsColors()
        {
            if (ApiInformation.IsTypePresent("Windows.UI.ViewManagement.ApplicationView"))
            {
                ApplicationViewTitleBar titleBar = ApplicationView.GetForCurrentView().TitleBar;

                if (titleBar != null)
                {
                    if (lastAccentColor != (Color)Resources["SystemAccentColor"])
                    {
                        lastAccentColor = (Color)Resources["SystemAccentColor"];
                        
                        titleBar.BackgroundColor = lastAccentColor;
                        titleBar.ForegroundColor = Colors.White;
                        titleBar.InactiveForegroundColor = Color.FromArgb(0xFF, 0x66, 0x66, 0x66);
                    
                        titleBar.InactiveBackgroundColor = titleBar.BackgroundColor;

                        titleBar.ButtonBackgroundColor = titleBar.BackgroundColor;
                        titleBar.ButtonForegroundColor = titleBar.ForegroundColor;

                        titleBar.ButtonHoverForegroundColor     = titleBar.ButtonForegroundColor;
                        titleBar.ButtonInactiveBackgroundColor  = titleBar.InactiveBackgroundColor;
                        titleBar.ButtonInactiveForegroundColor  = titleBar.InactiveForegroundColor;
                        titleBar.ButtonPressedForegroundColor   = titleBar.ButtonForegroundColor;
                    
                        titleBar.ButtonHoverBackgroundColor     = MixColors(titleBar.ButtonBackgroundColor, Color.FromArgb(0xFF, 0x19, 0x0D, 0x03));
                        titleBar.ButtonPressedBackgroundColor   = MixColors(titleBar.ButtonBackgroundColor, Color.FromArgb(0xFF, 0x33, 0x1B, 0x08));
                    }
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

            systemNavigationManager = SystemNavigationManager.GetForCurrentView();
            rootFrame = Window.Current.Content as Frame;

            if (rootFrame == null)
            {
                rootFrame = new Frame();
                rootFrame.NavigationFailed += OnNavigationFailed;

                rootFrame.Navigated += (sender, e) =>
                {
                    systemNavigationManager.AppViewBackButtonVisibility = rootFrame.CanGoBack ? AppViewBackButtonVisibility.Visible : AppViewBackButtonVisibility.Collapsed;
                };
                systemNavigationManager.BackRequested += (sender, e) =>
                {
                    if (rootFrame.CanGoBack)
                    {
                        e.Handled = true;
                        rootFrame.GoBack();
                    }
                };

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
            SuspendingDeferral deferral = e.SuspendingOperation.GetDeferral();

            await AppData.Current.SaveAsync();
            deferral.Complete();
        }
    }
}
