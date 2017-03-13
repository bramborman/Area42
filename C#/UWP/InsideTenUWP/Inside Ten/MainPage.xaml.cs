using System;
using UWPHelper.UI;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace InsideTen
{
    public sealed partial class MainPage : PageBase
    {
        private App App
        {
            get { return App.Current; }
        }
        private AppData AppData
        {
            get { return AppData.Current; }
        }
        private InsiderInfo InsiderInfo
        {
            get { return InsiderInfo.Current; }
        }

        public MainPage()
        {
            InitializeComponent();

            Loaded += async (sender, e) =>
            {
                if (AppData.ShowLoadingError)
                {
                    AppData.ShowLoadingError = false;

                    if (await new LoadingErrorDialog("settings", "with default settings").ShowAsync() == ContentDialogResult.Primary)
                    {
                        App.Current.Exit();
                    }
                    else
                    {
                        await AppData.Current.SaveAsync();
                    }
                }
            };
        }

        private void ToggleAbout(object sender, RoutedEventArgs e)
        {
            AppData.ShowAbout = !AppData.ShowAbout;
        }

        private void Settings(object sender, RoutedEventArgs e)
        {
            Frame.Navigate(typeof(Settings));
        }

        private async void RefreshAsync(object sender, RoutedEventArgs e)
        {
            await InsiderInfo.LoadAsync();
        }
    }
}
