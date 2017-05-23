using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace TicTacToe
{
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            InitializeComponent();
        }

        private void Play(object sender, RoutedEventArgs e)
        {
            if (int.TryParse(NTX_GameBoardSize.Text, out int gameBoardSize) && gameBoardSize >= 3 && gameBoardSize <= 10)
            {
                Frame.Navigate(typeof(Game), gameBoardSize);
            }
        }
    }
}
