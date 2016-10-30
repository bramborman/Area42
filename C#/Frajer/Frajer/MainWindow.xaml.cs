using System;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;

namespace Frajer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            tb_input.Focus();
        }

        private void Test(object sender, RoutedEventArgs e)
        {
            bool match = false;
            string name = "";
            string[] names =
            {
                "fisa",
                "veverkova",
                "adriana",
                "adrianka",
                "adrinka",
                "adra",
            };
            
            tb_result.Text = tb_input.Text + " ";
            tb_input.Text = tb_input.Text.ToLower();

            for (int i = 0; i < tb_input.Text.Length; i++)
            {
                if (tb_input.Text[i] == 'ě' || tb_input.Text[i] == 'é')
                {
                    name += 'e';
                }
                else if (tb_input.Text[i] == 'š')
                {
                    name += 's';
                }
                else if (tb_input.Text[i] == 'č')
                {
                    name += 'c';
                }
                else if (tb_input.Text[i] == 'ř')
                {
                    name += 'r';
                }
                else if (tb_input.Text[i] == 'ž')
                {
                    name += 'z';
                }
                else if (tb_input.Text[i] == 'ý')
                {
                    name += 'y';
                }
                else if (tb_input.Text[i] == 'á')
                {
                    name += 'a';
                }
                else if (tb_input.Text[i] == 'í')
                {
                    name += 'i';
                }
                else
                {
                    name += tb_input.Text[i];
                }
            }

            for (int i = 0; i < names.Length; i++)
            {
                if (name == names[i])
                {
                    tb_result.Text += "není frajer";
                    match = true;

                    break;
                }
            }

            if (match == false)
            {
                if (name == "skalka")
                {
                    tb_result.Text = "Error 0x0008e65";
                }
                else if (name == "pelcl")
                {
                    tb_result.Text += "je chlupáček :3";
                }
                else
                {
                    tb_result.Text += "je frajer";
                }
            }

            gr_result.Visibility = Visibility.Visible;
            bt_reset.Focus();
        }

        private void ResetWithEnter(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Escape)
            {
                Reset(sender, e as RoutedEventArgs);
            }
        }

        private void Reset(object sender, RoutedEventArgs e)
        {
            tb_input.Text = "";
            tb_input.Focus();

            gr_result.Visibility = Visibility.Collapsed;
        }

        private void InputFocus(object sender, MouseButtonEventArgs e)
        {
            tb_input.Focus();
        }

        private void InputSubmit(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                Test(sender, e as RoutedEventArgs);
            }
        }

        private void Window_Activated(object sender, EventArgs e)
        {
            this.BorderBrush = new SolidColorBrush(Color.FromRgb(51, 51, 51));

            tb_title.Foreground = new SolidColorBrush(Colors.White);

            bt_minimize.Foreground = new SolidColorBrush(Colors.White);
            bt_close.Foreground = new SolidColorBrush(Colors.White);
        }

        private void Window_Deactivated(object sender, EventArgs e)
        {
            this.BorderBrush = new SolidColorBrush(Colors.Gray);

            tb_title.Foreground = new SolidColorBrush(Colors.Gray);

            bt_minimize.Foreground = new SolidColorBrush(Colors.Gray);
            bt_close.Foreground = new SolidColorBrush(Colors.Gray);
        }

        private void WindowDrag(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
            {
                this.DragMove();
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