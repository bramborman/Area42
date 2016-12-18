using System;
using System.ComponentModel;
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
    public sealed partial class App : Application, INotifyPropertyChanged
    {
        public static new App Current { get; private set; }

        private readonly Color[] lightOverlayColors = { Color.FromArgb(0x19, 0xFF, 0xFF, 0xFF), Color.FromArgb(0x33, 0xFF, 0xFF, 0xFF) };
        private readonly Color[] darkOverlayColors  = { Color.FromArgb(0x19, 0x00, 0x00, 0x00), Color.FromArgb(0x33, 0x00, 0x00, 0x00) };

        private bool isTitleBarAvailable;
        private bool isStatusBarAvailable;
        private ElementTheme _contrastingColorTheme;
        private Color lastAccentColor;
        private Frame rootFrame;
        private ApplicationViewTitleBar titleBar;
        private StatusBar statusBar;
        private SystemNavigationManager systemNavigationManager;

        //TODO: this
        private bool IsLightOverlay
        {
            get
            {
                return true;
            }
        }

        public ElementTheme ContrastingColorTheme
        {
            get { return _contrastingColorTheme; }
            set
            {
                if (_contrastingColorTheme != value)
                {
                    _contrastingColorTheme = value;
                    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(ContrastingColorTheme)));
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

        // Original taken from http://stackoverflow.com/a/9955317/6843321
        public static Color MixColors(Color foreground, Color? background)
        {
            if (foreground.A == 0xFF)
            {
                throw new Exception("You're not doing it right ;)");
            }

            double alpha      = foreground.A / 255.0;
            double difference = 1.0 - alpha;

            byte r = (byte)((foreground.R * alpha) + (background.Value.R * difference));
            byte g = (byte)((foreground.G * alpha) + (background.Value.G * difference));
            byte b = (byte)((foreground.B * alpha) + (background.Value.B * difference));

            return Color.FromArgb(0xFF, r, g, b);
        }
        
        public void SetColors()
        {
            if (lastAccentColor != (Color)Resources["SystemAccentColor"])
            {
                lastAccentColor = (Color)Resources["SystemAccentColor"];
                ContrastingColorTheme = IsLightOverlay ? ElementTheme.Dark : ElementTheme.Light;

                if (isTitleBarAvailable)
                {
                    titleBar.BackgroundColor                = lastAccentColor;
                    titleBar.ButtonBackgroundColor          = titleBar.BackgroundColor;

                    // Use default system colors in inactive state
                    //x titleBar.InactiveBackgroundColor        = WhatheverColor;
                    //x titleBar.InactiveForegroundColor        = WhatheverColor;
                    //x titleBar.ButtonInactiveBackgroundColor  = WhatheverColor;
                    //x titleBar.ButtonInactiveForegroundColor  = WhatheverColor;
                    
                    if (IsLightOverlay)
                    {
                        titleBar.ForegroundColor = Colors.White;

                        titleBar.ButtonHoverBackgroundColor   = MixColors(lightOverlayColors[0], titleBar.ButtonBackgroundColor);
                        titleBar.ButtonPressedBackgroundColor = MixColors(lightOverlayColors[1], titleBar.ButtonBackgroundColor);
                    }
                    else
                    {
                        titleBar.ForegroundColor = Colors.Black;

                        titleBar.ButtonHoverBackgroundColor   = MixColors(darkOverlayColors[0], titleBar.ButtonBackgroundColor);
                        titleBar.ButtonPressedBackgroundColor = MixColors(darkOverlayColors[1], titleBar.ButtonBackgroundColor);
                    }

                    // Don't change foreground colors when buttons are in different states
                    titleBar.ButtonForegroundColor          = titleBar.ForegroundColor;
                    titleBar.ButtonHoverForegroundColor     = titleBar.ForegroundColor;
                    titleBar.ButtonPressedForegroundColor   = titleBar.ForegroundColor;
                }

                if (isStatusBarAvailable)
                {
                    statusBar.BackgroundColor = lastAccentColor;
                    statusBar.ForegroundColor = IsLightOverlay ? Colors.White : Colors.Black;
                }
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
                        SetColors();
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
