using System;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace PAP.Game
{
    public partial class GamePage : Page
    {
        public static readonly Size requestedSize = new Size(288d, 432d);

        public static GamePage Instance { get; } = new GamePage();

        private bool canClose = false;

        static GamePage()
        {
            RequestedSizeProperty.OverrideMetadata(typeof(GamePage), new FrameworkPropertyMetadata(requestedSize));
        }

        private GamePage()
        {
            InitializeComponent();

            //PauseMenu.Instance.Visibility = Visibility.Collapsed;
            //grid.Children.Add(PauseMenu.Instance);
        }

        public void ShowAnimated(double planeWidth, double planeHeight, double planeLeft, double planeTop)
        {
            plane.Width = planeWidth;
            plane.Height = planeHeight;
            plane.Left = planeLeft;
            plane.Top = planeTop;

            MainWindow.Instance.Content = this;
            GameManager.Start();
        }

        public void ShowPauseMenu()
        {
            PauseMenu.Instance.ShowAnimated();
        }

        public override Task<bool> CanCloseAsync()
        {
            if (canClose)
            {
                TaskCompletionSource<bool> tcs = new TaskCompletionSource<bool>();
                Rectangle rectangle = new Rectangle()
                {
                    Fill = (Brush)Application.Current.Resources["BackgroundBrush"],
                    Opacity = 0d
                };

                ((Panel)Content).Children.Add(rectangle);

                Storyboard opacityShowingAnimation = ((Storyboard)Application.Current.Resources["OpacityShowingAnimation"]).Clone();
                opacityShowingAnimation.Completed += OpacityShowingAnimation_Completed;
                opacityShowingAnimation.Begin(rectangle);

                return tcs.Task;


                void OpacityShowingAnimation_Completed(object sender, EventArgs e)
                {
                    tcs.SetResult(true);
                }
            }
            else
            {
                ShowPauseMenu();
                return Task.FromResult(false);
            }
        }
    }
}
