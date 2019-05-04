using System.Windows.Input;

namespace PAP
{
    public sealed partial class About : Page
    {
        public static About Instance { get; } = new About();

        private About()
        {
            InitializeComponent();
        }

        private async void GoBackAsync(object sender, ExecutedRoutedEventArgs e)
        {
            await Frame.NavigateAsync(Menu.Instance);
        }
    }
}
