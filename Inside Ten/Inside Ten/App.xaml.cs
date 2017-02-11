using System;
using System.ComponentModel;
using System.Threading.Tasks;
using UWPHelper.Utilities;
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
    public sealed partial class App : Application, INotifyPropertyChanged
    {
        public static new App Current { get; private set; }

        private readonly Color[] lightOverlayColors = { Color.FromArgb(0x19, 0xFF, 0xFF, 0xFF), Color.FromArgb(0x33, 0xFF, 0xFF, 0xFF) };
        private readonly Color[] darkOverlayColors  = { Color.FromArgb(0x19, 0x00, 0x00, 0x00), Color.FromArgb(0x33, 0x00, 0x00, 0x00) };

        private bool isTitleBarAvailable;
        private bool isStatusBarAvailable;
        private ElementTheme _currentTheme;
        private ElementTheme _contrastingTheme;
        private Color _lastAccentColor;
        private Frame rootFrame;
        private ApplicationViewTitleBar titleBar;
        private StatusBar statusBar;
        private SystemNavigationManager systemNavigationManager;
        
        private Color LastAccentColor
        {
            get { return _lastAccentColor; }
            set
            {
#if DEBUG
                if (_lastAccentColor == value)
                {
                    throw new Exception("You're not doing it right ;)");
                }
#endif
                _lastAccentColor = value;
                    
                float luma = _lastAccentColor.GetLuma();
                IsLightOverlay = luma < 0.4869937f || luma == 0.541142f;

                ContrastingTheme = IsLightOverlay ? ElementTheme.Dark : ElementTheme.Light;
            }
        }
        private bool IsLightOverlay { get; set; }

        public ElementTheme CurrentTheme
        {
            get { return _currentTheme; }
            private set
            {
                if (_currentTheme != value)
                {
                    _currentTheme = value;
                    OnPropertyChanged(nameof(CurrentTheme));
                }
            }
        }
        public ElementTheme ContrastingTheme
        {
            get { return _contrastingTheme; }
            private set
            {
                if (_contrastingTheme != value)
                {
                    _contrastingTheme = value;
                    OnPropertyChanged(nameof(ContrastingTheme));
                }
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        public App()
        {
            Current = this;

            InitializeComponent();
            Suspending += OnSuspending;
        }

        private void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
        
        private void SetColors()
        {
            if (LastAccentColor != (Color)Resources["SystemAccentColor"])
            {
                LastAccentColor = (Color)Resources["SystemAccentColor"];

                if (isTitleBarAvailable)
                {
                    titleBar.BackgroundColor                = LastAccentColor;
                    titleBar.ButtonBackgroundColor          = titleBar.BackgroundColor;

                    // Use default system colors in inactive state
                    //x titleBar.InactiveBackgroundColor        = WhatheverColor;
                    //x titleBar.InactiveForegroundColor        = WhatheverColor;
                    //x titleBar.ButtonInactiveBackgroundColor  = WhatheverColor;
                    //x titleBar.ButtonInactiveForegroundColor  = WhatheverColor;

                    if (IsLightOverlay)
                    {
                        titleBar.ForegroundColor = Colors.White;

                        titleBar.ButtonHoverBackgroundColor   = titleBar.ButtonBackgroundColor.Value.Mix(lightOverlayColors[0]);
                        titleBar.ButtonPressedBackgroundColor = titleBar.ButtonBackgroundColor.Value.Mix(lightOverlayColors[1]);
                    }
                    else
                    {
                        titleBar.ForegroundColor = Colors.Black;

                        titleBar.ButtonHoverBackgroundColor   = titleBar.ButtonBackgroundColor.Value.Mix(darkOverlayColors[0]);
                        titleBar.ButtonPressedBackgroundColor = titleBar.ButtonBackgroundColor.Value.Mix(darkOverlayColors[1]);
                    }

                    // Don't change foreground colors when buttons are in different states
                    titleBar.ButtonForegroundColor          = titleBar.ForegroundColor;
                    titleBar.ButtonHoverForegroundColor     = titleBar.ForegroundColor;
                    titleBar.ButtonPressedForegroundColor   = titleBar.ForegroundColor;
                }

                if (isStatusBarAvailable)
                {
                    statusBar.BackgroundColor = LastAccentColor;
                    statusBar.ForegroundColor = IsLightOverlay ? Colors.White : Colors.Black;
                }
            }
        }

#pragma warning disable IDE1006 // Naming Styles
        protected override async void OnActivated(IActivatedEventArgs args)
#pragma warning restore IDE1006 // Naming Styles
        {
            bool loadAppData         = AppData.Current == null;
            bool loadInsiderInfo     = InsiderInfo.Current == null;
            Task loadAppDataTask     = null;
            Task loadInsiderInfoTask = null;

            if (loadAppData)
            {
                loadAppDataTask = AppData.LoadAsync();
            }

            if (loadInsiderInfo)
            {
                loadInsiderInfoTask = InsiderInfo.LoadAsync();
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
                    isTitleBarAvailable = titleBar != null;

                    ApplicationView.GetForCurrentView().SetPreferredMinSize(new Size(330, 460));
                }

                if (ApiInformation.IsTypePresent("Windows.UI.ViewManagement.StatusBar"))
                {
                    statusBar = StatusBar.GetForCurrentView();
                    isStatusBarAvailable = statusBar != null;

                    if (isStatusBarAvailable)
                    {
                        statusBar.BackgroundOpacity = 1;
                    }
                }

                SetColors();
                Window.Current.Activated += (sender, e) =>
                {
                    if (e.WindowActivationState != CoreWindowActivationState.Deactivated)
                    {
                        CurrentTheme = RequestedTheme == ApplicationTheme.Light ? ElementTheme.Light : ElementTheme.Dark;
                        SetColors();
                    }
                };
            }
            
            LaunchActivatedEventArgs launchArgs = args as LaunchActivatedEventArgs;

            if (loadAppData)
            {
                await loadAppDataTask;
            }

            if (loadInsiderInfo)
            {
                await loadInsiderInfoTask;
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

#pragma warning disable IDE1006 // Naming Styles
        private async void OnSuspending(object sender, SuspendingEventArgs e)
#pragma warning restore IDE1006 // Naming Styles
        {
            SuspendingDeferral deferral = e.SuspendingOperation.GetDeferral();

            await AppData.Current.SaveAsync();
            deferral.Complete();
        }
    }
}
