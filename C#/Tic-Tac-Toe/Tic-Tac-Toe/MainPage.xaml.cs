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
            int gameBoardSize;

            if (int.TryParse(TX_GameBoardSize.Text, out gameBoardSize) && gameBoardSize >= 3 && gameBoardSize <= 10)
            {
                Frame.Navigate(typeof(Game), gameBoardSize);
            }
        }
    }
}
