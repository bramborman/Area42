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
        private readonly Color[] lightOverlayColors = { Color.FromArgb(0xFF, 0x19, 0x0D, 0x03), Color.FromArgb(0xFF, 0x33, 0x1B, 0x08) };
        private readonly Color[] darkOverlayColors  = { new Color(), new Color() };
        
        private Color lastAccentColor;
        private Frame rootFrame;
        private ApplicationViewTitleBar titleBar;
        private StatusBar statusBar;
        private SystemNavigationManager systemNavigationManager;

        public App()
        {
            InitializeComponent();
            Suspending += OnSuspending;
        }
        
        //TODO: this
        private bool IsLightOverlay()
        {
            return true;
        }
        
        private Color? MixColors(Color? first, Color? second)
        {
            return Color.FromArgb(0xFF, (byte)Math.Min(first.Value.R + second.Value.R, 0xFF), (byte)Math.Min(first.Value.G + second.Value.G, 0xFF), (byte)Math.Min(first.Value.B + second.Value.B, 0xFF));
        }
        
        public void SetBarsColors()
        {
            if (titleBar != null)
            {
                if (lastAccentColor != (Color)Resources["SystemAccentColor"])
                {
                    lastAccentColor = (Color)Resources["SystemAccentColor"];
                        
                    titleBar.BackgroundColor                = lastAccentColor;
                    titleBar.ForegroundColor                = Colors.White;
                    titleBar.InactiveForegroundColor        = Color.FromArgb(0xFF, 0x66, 0x66, 0x66);
                    
                    titleBar.InactiveBackgroundColor        = titleBar.BackgroundColor;

                    titleBar.ButtonBackgroundColor          = titleBar.BackgroundColor;
                    titleBar.ButtonForegroundColor          = titleBar.ForegroundColor;

                    titleBar.ButtonHoverForegroundColor     = titleBar.ButtonForegroundColor;
                    titleBar.ButtonInactiveBackgroundColor  = titleBar.InactiveBackgroundColor;
                    titleBar.ButtonInactiveForegroundColor  = titleBar.InactiveForegroundColor;
                    titleBar.ButtonPressedForegroundColor   = titleBar.ButtonForegroundColor;
                    
                    if (IsLightOverlay())
                    {
                        titleBar.ButtonHoverBackgroundColor   = MixColors(titleBar.ButtonBackgroundColor, lightOverlayColors[0]);
                        titleBar.ButtonPressedBackgroundColor = MixColors(titleBar.ButtonBackgroundColor, lightOverlayColors[1]);
                    }
                    else
                    {
                        titleBar.ButtonHoverBackgroundColor   = MixColors(titleBar.ButtonBackgroundColor, darkOverlayColors[0]);
                        titleBar.ButtonPressedBackgroundColor = MixColors(titleBar.ButtonBackgroundColor, darkOverlayColors[1]);
                    }
                }
            }
            
            if (statusBar != null)
            {
                statusBar.BackgroundOpacity = 1;

                statusBar.BackgroundColor = (Color)Resources["SystemAccentColor"];
                statusBar.ForegroundColor = Color.FromArgb(0xFF, 0xC7, 0xC7, 0xC7);
            }
        }

        protected override async void OnActivated(IActivatedEventArgs args)
        {
            bool loadAppData     = AppData.Current == null;
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
                    titleBar = ApplicationView.GetForCurrentView().TitleBar;
                    ApplicationView.GetForCurrentView().SetPreferredMinSize(new Size(330, 460));
                }

                if (ApiInformation.IsTypePresent("Windows.UI.ViewManagement.StatusBar"))
                {
                    statusBar = StatusBar.GetForCurrentView();
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

        protected override void OnLaunched(LaunchActivatedEventArgs e)
        {
            OnActivated(e);
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
