using PAP.Game;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media.Animation;

namespace PAP
{
    public sealed partial class Menu : Page
    {
        private readonly ParallelTimeline goUpDownWindowResizeAnimationAddition;
        private readonly Storyboard goUpDownAnimation;
        private readonly Storyboard flyAnimation;

        private bool isUp = true;

        public static Menu Instance { get; } = new Menu();

        private Menu()
        {
            InitializeComponent();

            goUpDownAnimation = ((Storyboard)MainWindow.Instance.Resources["ResizeAnimation"]).Clone();
            ChangeKeyTimeOfAllKeyFrames(goUpDownAnimation, (KeyTime)Application.Current.Resources["AnimationKeyTime"]);

            IEasingFunction goUpDownAnimationEasingFunction = (IEasingFunction)Application.Current.Resources["AnimationEasingFunction"];

            foreach (IKeyFrameAnimation animation in goUpDownAnimation.Children)
            {
                ((EasingDoubleKeyFrame)animation.KeyFrames[0]).EasingFunction = goUpDownAnimationEasingFunction;
            }

            goUpDownWindowResizeAnimationAddition = (ParallelTimeline)Resources["GoUpDownWindowResizeAnimationAddition"];
            goUpDownAnimation.Children.Add(goUpDownWindowResizeAnimationAddition);

            flyAnimation = ((Storyboard)MainWindow.Instance.Resources["ResizeAnimation"]).Clone();
            ChangeKeyTimeOfAllKeyFrames(flyAnimation, (KeyTime)Resources["FlyKeyTime"]);
            flyAnimation.Children.Add((ParallelTimeline)Resources["FlyWindowResizeAnimationAddition"]);


            void ChangeKeyTimeOfAllKeyFrames(TimelineGroup timelineGroup, KeyTime keyTime)
            {
                foreach (IKeyFrameAnimation animation in timelineGroup.Children)
                {
                    ((IKeyFrame)animation.KeyFrames[0]).KeyTime = keyTime;
                }
            }
        }

        private async void FlyAsync(object sender, ExecutedRoutedEventArgs e)
        {
            if (isUp)
            {
                await MainWindow.Instance.ResizeAsync(new Size(72d, 72d), flyAnimation);

                down.Visibility = Visibility.Collapsed;
                more.Visibility = Visibility.Collapsed;

                await Frame.NavigateAsync(MenuToGameTransition.Instance, false);
            }
        }

        private async void GoDownAsync(object sender, ExecutedRoutedEventArgs e)
        {
            if (isUp)
            {
                Helpers.SetAnimationKeyFrameValue(goUpDownWindowResizeAnimationAddition, 0, 0, -144d);
                Helpers.SetAnimationKeyFrameValue(goUpDownWindowResizeAnimationAddition, 1, 0, 0d);

                Size size = new Size(72d, 216d);

                await MainWindow.Instance.ResizeAsync(size, goUpDownAnimation).ContinueWith(task =>
                {
                    Dispatcher.Invoke(() =>
                    {
                        RequestedSize = size;
                    });

                    isUp = false;
                });
            }
        }

        private async void GoUpAsync(object sender, ExecutedRoutedEventArgs e)
        {
            if (!isUp)
            {
                Helpers.SetAnimationKeyFrameValue(goUpDownWindowResizeAnimationAddition, 0, 0, 0d);
                Helpers.SetAnimationKeyFrameValue(goUpDownWindowResizeAnimationAddition, 1, 0, 144d);

                Size size = new Size(72d, 144d);

                await MainWindow.Instance.ResizeAsync(size, goUpDownAnimation).ContinueWith(task =>
                {
                    Dispatcher.Invoke(() =>
                    {
                        RequestedSize = size;
                    });

                    isUp = true;
                });
            }
        }

        private async void ShowAboutPageAsync(object sender, ExecutedRoutedEventArgs e)
        {
            if (!isUp)
            {
                await Frame.NavigateAsync(About.Instance);
            }
        }
        
        private void Close(object sender, ExecutedRoutedEventArgs e)
        {
            if (!isUp)
            {
                MainWindow.Instance.Close();
            }
        }
    }
}
