using System;
using System.ComponentModel;
using System.Threading.Tasks;
using UWPHelper.UI;
using Windows.ApplicationModel;
using Windows.ApplicationModel.Activation;
using Windows.Foundation;
using Windows.Foundation.Metadata;
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
        
        private Frame rootFrame;
        private SystemNavigationManager systemNavigationManager;
        private ElementTheme _currentTheme;

        public ElementTheme CurrentTheme
        {
            get { return _currentTheme; }
            set
            {
                if (_currentTheme != value)
                {
                    _currentTheme = value;
                    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(CurrentTheme)));
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

                await BarsHelper.Current.SetTitleBarColorModeAsync(BarsHelperColorMode.Accent);
                await BarsHelper.Current.SetStatusBarColorModeAsync(BarsHelperColorMode.Accent);
                await BarsHelper.Current.InitializeForCurrentViewAsync();

                if (ApiInformation.IsTypePresent("Windows.UI.ViewManagement.ApplicationView"))
                {
                    ApplicationView.GetForCurrentView().SetPreferredMinSize(new Size(330, 460));
                }

                Window.Current.Activated += (sender, e) =>
                {
                    if (e.WindowActivationState != CoreWindowActivationState.Deactivated)
                    {
                        CurrentTheme = RequestedTheme == ApplicationTheme.Light ? ElementTheme.Light : ElementTheme.Dark;
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
