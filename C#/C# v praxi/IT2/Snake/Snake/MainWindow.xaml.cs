using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace Snake
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        const int SIZE = 10;
        const int MOVE = SIZE / 5;
        const int DEFAULTCOUNT = 10;
        const int MAXBODIES = 100;
        const int MAXCOUNT = DEFAULTCOUNT + (MAXBODIES * SIZE);
        
        bool firstDirectionLoaded = false;
        int count = DEFAULTCOUNT;
        double x, y, xBerry, yBerry;

        Key direction = Key.Up;
        Key firstDirection = Key.Up;
        Key secondDirection = Key.Up;

        Ellipse berry = new Ellipse();
        DispatcherTimer timer = new DispatcherTimer();
        SolidColorBrush head = new SolidColorBrush(Color.FromRgb(23, 144, 255));
        SolidColorBrush main = new SolidColorBrush(Colors.Black);
        List<Ellipse> snake = new List<Ellipse>();

        public MainWindow()
        {
            InitializeComponent();
            
            berry.Width = SIZE;
            berry.Height = SIZE;
            berry.Fill = new SolidColorBrush(Color.FromRgb(22, 137, 230));

            timer.Tick += timer_Tick;
            timer.Interval = new TimeSpan(0, 0, 0, 0, 10);
            timer.Start();

            Loaded += delegate
            {
                x = cv_board.ActualWidth / 2;
                y = cv_board.ActualHeight / 2;

                NewBerry();
            };
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            Ellipse el = new Ellipse();

            el.Width = SIZE;
            el.Height = SIZE;

            el.Fill = head;
            el.Stroke = main;
            el.StrokeThickness = 1;

            if (x % SIZE == 0 && y % SIZE == 0)
            {
                direction = firstDirection;

                if (firstDirection != secondDirection)
                {
                    firstDirection = secondDirection;
                }

                firstDirectionLoaded = false;
            }

            if (direction == Key.Up)
            {
                y -= SIZE / 5;
            }
            else if (direction == Key.Down)
            {
                y += SIZE / 5;
            }
            else if (direction == Key.Left)
            {
                x -= SIZE / 5;
            }
            else if (direction == Key.Right)
            {
                x += SIZE / 5;
            }

            Canvas.SetLeft(el, x);
            Canvas.SetTop(el, y);

            snake.Add(el);

            for (int i = 0; i < snake.Count - 1; i++)
            {
                if (Canvas.GetLeft(snake[snake.Count - 1]) == Canvas.GetLeft(snake[i]) && Canvas.GetTop(snake[snake.Count - 1]) == Canvas.GetTop(snake[i]))
                {
                    timer.Stop();
                    cv_board.Children.Clear();

                    lb_message.Visibility = Visibility.Visible;
                    lb_message.Content = "YOU DIED";
                    
                    return;
                }
            }
            
            if (x < 0 || x > cv_board.ActualWidth || y < 0 || y > cv_board.ActualHeight)
            {
                timer.Stop();
                cv_board.Children.Clear();

                lb_message.Visibility = Visibility.Visible;
                lb_message.Content = "YOU DIED";
            }
            else if (count == MAXCOUNT)
            {
                timer.Stop();
                cv_board.Children.Clear();

                lb_message.Visibility = Visibility.Visible;
                lb_message.Content = "YOU WON";
            }
            else
            {
                if (snake.Count == count)
                {
                    cv_board.Children.Remove(snake[0]);
                    snake.Remove(snake[0]);
                }

                if (snake.Count > 1)
                {
                    snake[snake.Count - 2].Fill = main;
                }

                if (x == xBerry && y == yBerry)
                {
                    cv_board.Children.Remove(berry);
                    NewBerry();

                    count += SIZE;
                    tb_score.Text = "Score: " + ((count - DEFAULTCOUNT) / SIZE).ToString();
                }

                cv_board.Children.Add(snake[snake.Count - 1]);
            }
        }

        private void NewBerry()
        {
            int i;
            Random rn = new Random();

            do
            {
                do
                {
                    xBerry = rn.Next((int)(cv_board.ActualWidth / 2));
                } while (xBerry % SIZE != 0);

                do
                {
                    yBerry = rn.Next((int)(cv_board.ActualHeight / 2));
                } while (yBerry % SIZE != 0);

                for (i = 0; i < snake.Count; i++)
                {
                    if (xBerry == Canvas.GetLeft(snake[i]) && yBerry == Canvas.GetTop(snake[i]))
                    {
                        break;
                    }
                }
            } while (i != snake.Count);

            Canvas.SetLeft(berry, xBerry);
            Canvas.SetTop(berry, yBerry);

            cv_board.Children.Add(berry);
        }

        private void ShowMessage(bool win)
        {

        }

        private void SnakeWindow_KeyDown(object sender, KeyEventArgs e)
        {
            if (
                    timer.IsEnabled &&
                    (
                        (e.Key == Key.Up && firstDirection != Key.Down) ||
                        (e.Key == Key.Down && firstDirection != Key.Up) ||
                        (e.Key == Key.Right && firstDirection != Key.Left) ||
                        (e.Key == Key.Left && firstDirection != Key.Right)
                    )
                )
            {
                if (!firstDirectionLoaded)
                {
                    firstDirection = secondDirection = e.Key;
                    firstDirectionLoaded = true;
                }
                else
                {
                    secondDirection = e.Key;
                }
            }
            else if (e.Key == Key.Escape)
            {
                timer.IsEnabled = !timer.IsEnabled;
            }
        }

        private void SnakeWindow_Activated(object sender, EventArgs e)
        {
            BorderBrush = new SolidColorBrush(Color.FromRgb(17, 107, 179));

            tb_title.Foreground = new SolidColorBrush(Colors.White);
            tb_score.Foreground = new SolidColorBrush(Colors.White);

            bt_minimize.Foreground = new SolidColorBrush(Colors.White);
            bt_close.Foreground = new SolidColorBrush(Colors.White);
        }

        private void SnakeWindow_Deactivated(object sender, EventArgs e)
        {
            timer.IsEnabled = false;

            BorderBrush = new SolidColorBrush(Color.FromRgb(51, 51, 51));

            tb_title.Foreground = new SolidColorBrush(Colors.Gray);
            tb_score.Foreground = new SolidColorBrush(Colors.Gray);

            bt_minimize.Foreground = new SolidColorBrush(Colors.Gray);
            bt_close.Foreground = new SolidColorBrush(Colors.Gray);
        }

        private void WindowDrag(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
            {
                DragMove();
            }
        }

        private void Minimize(object sender, RoutedEventArgs e)
        {
            WindowState = WindowState.Minimized;
        }

        private void Close(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }
    }
}
