using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace MoreViewsTest
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
        }

        private void ChangeTheme(object sender, RoutedEventArgs e)
        {
            int theme = (int)AppData.Theme;

            if (++theme == 3)
            {
                theme = 0;
            }

            AppData.Theme = (ElementTheme)theme;
        }
    }
}
