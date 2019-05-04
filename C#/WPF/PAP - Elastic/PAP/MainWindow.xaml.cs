using System;
using System.ComponentModel;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Animation;

namespace PAP
{
    public sealed partial class MainWindow : Window
    {
        private static readonly double dropShadowPanelFullMarginSize = 2d * (double)Application.Current.Resources["DropShadowPanelMarginSize"];

        public static MainWindow Instance { get; } = new MainWindow();

        private bool canClose = false;
        private bool closing = false;
        private bool showing = false;
        private bool shown = false;
        
        private MainWindow()
        {
            InitializeComponent();

            Left = (SystemParameters.PrimaryScreenWidth - Width) / 2d;
            Top = (SystemParameters.PrimaryScreenHeight - Height) / 2d;
        }

        public (Size size, Point position, Size backgroundScale, bool areEqual) MeasureResize(Size size)
        {
            double scaleX = size.Width / background.ActualWidth;
            double scaleY = size.Height / background.ActualHeight;

            size.Width += dropShadowPanelFullMarginSize;
            size.Height += dropShadowPanelFullMarginSize;
            double left = Left - ((size.Width - Width) / 2d);
            double top = Top - ((size.Height - Height) / 2d);

            ScaleTransform backgroundScaleTransform = (ScaleTransform)background.RenderTransform;

            return (new Size(size.Width, size.Height),
                    new Point(left, top),
                    new Size(scaleX, scaleY),
                    scaleX == backgroundScaleTransform.ScaleX && scaleY == backgroundScaleTransform.ScaleY);
        }

        public Task ResizeAsync(Size size)
        {
            return ResizeAsync(size, (Storyboard)Resources["ResizeAnimation"]);
        }
        
        public Task ResizeAsync(Size size, Storyboard resizeAnimation)
        {
            (Size size, Point position, Size backgroundScale, bool areEqual) values = MeasureResize(size);

            if (values.areEqual)
            {
                return Task.CompletedTask;
            }

            if (ActualWidth < values.size.Width)
            {
                Width = values.size.Width;
            }

            if (ActualHeight < values.size.Height)
            {
                Height = values.size.Height;
            }

            if (!shown)
            {
                ScaleTransform scaleTransform = (ScaleTransform)background.RenderTransform;
                scaleTransform.ScaleX = values.backgroundScale.Width;
                scaleTransform.ScaleY = values.backgroundScale.Height;

                return Task.CompletedTask;
            }
            
            Helpers.SetAnimationKeyFrameValue(resizeAnimation, 0, 0, values.position.X);
            Helpers.SetAnimationKeyFrameValue(resizeAnimation, 1, 0, values.position.Y);
            Helpers.SetAnimationKeyFrameValue(resizeAnimation, 2, 0, values.backgroundScale.Width);
            Helpers.SetAnimationKeyFrameValue(resizeAnimation, 3, 0, values.backgroundScale.Height);

            return Helpers.RunStoryboardAsync(resizeAnimation, this).ContinueWith(task =>
            {
                Dispatcher.Invoke(() =>
                {
                    if (ActualWidth > values.size.Width)
                    {
                        Width = values.size.Width;
                    }

                    if (ActualHeight > values.size.Height)
                    {
                        Height = values.size.Height;
                    }
                });
            });
        }
        
        public Task ShowAnimatedAsync()
        {
            if (!shown && !showing)
            {
                showing = true;
                
                ScaleTransform scaleTransform = (ScaleTransform)grid.RenderTransform;
                scaleTransform.ScaleX = 0d;
                scaleTransform.ScaleY = 0d;

                Show();
                shown = true;

                return Helpers.RunStoryboardAsync("OpeningAnimation", Resources).ContinueWith(task =>
                {
                    showing = false;
                });
            }

            return Task.CompletedTask;
        }

        protected override async void OnClosing(CancelEventArgs e)
        {
            base.OnClosing(e);

            if (!canClose && !e.Cancel)
            {
                e.Cancel = true;

                if (!closing)
                {
                    closing = true;

                    if (!(await frame.CanCloseAsync()))
                    {
                        closing = false;
                        return;
                    }

                    await Helpers.RunStoryboardAsync("ClosingAnimation", Resources);

                    canClose = true;
                    closing = false;
                    Close();
                }
            }
        }

        protected override void OnActivated(EventArgs e)
        {
            if (!closing)
            {
                canClose = false;
            }

            base.OnActivated(e);
        }

        protected override void OnDeactivated(EventArgs e)
        {
            base.OnDeactivated(e);

            if (!closing)
            {
                canClose = true;
            }
        }

        private async void Window_LoadedAsync(object sender, RoutedEventArgs e)
        {
            await frame.NavigateAsync(Menu.Instance, false);
        }
    }
}
