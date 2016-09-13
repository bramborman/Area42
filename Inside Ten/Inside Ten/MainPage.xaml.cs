using System;
using UWPHelper.UI;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace InsideTen
{
    public sealed partial class MainPage : Page
    {
        private AppData AppData
        {
            get { return AppData.Current; }
        }

        public MainPage()
        {
            InitializeComponent();

            Loaded += async (sender, e) =>
            {
                if (AppData.ShowLoadingError)
                {
                    AppData.ShowLoadingError = false;
                    await LoadingErrorDialog.ShowAsync("Settings", true);

                    // If it gets there it means that PrimaryButton weren't pressed so rewrite maybe corrupted appData file
                    await AppData.Current.SaveAsync();
                }
            };
        }

        private void ToggleAbout(object sender, RoutedEventArgs e)
        {
            AppData.ShowAbout = !AppData.ShowAbout;
        }
    }
}