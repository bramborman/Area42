using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace Modern_Calculator
{
    /// <summary>
    /// Calculator.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();

            if (Universal.menuhold == true) gr_menu.Visibility = Visibility.Visible;
            ch_menuhold.IsChecked = Universal.menuhold;

            tx_memory.Text = Universal.memory[0];
        }

        Boolean del = false;
        Int16 from = 10, to = 10;
        Double x = 0, y = 0, v = 0;
        String op = "";
        Color SmurfetBlue = Color.FromArgb(255, 88, 182, 255);

        private void ClearAll()
        {
            del = false;
            x = 0;
            y = 0;
            v = 0;
            op = "";

            tx_output.Text = "";

            Universal.error = false;
        }

        private void Clear(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "C") tx_output.Text = "";
            else if (((Button)sender).Content.ToString() == "AC") ClearAll();
            else if (((Button)sender).Content.ToString() == "←" && tx_output.Text != "") tx_output.Text = tx_output.Text.Remove(tx_output.Text.Length - 1, 1);
        }

        private void ClearButton(object sender, TextChangedEventArgs e)
        {
            if (tx_output.Text == "") bt_clear.Content = "AC";
            else bt_clear.Content = "C";
        }
        private void Add(object sender, RoutedEventArgs e)
        {
            if (tx_output.Text != "0")
            {
                if (del == false) tx_output.Text += ((Button)sender).Content.ToString();
                else
                {
                    tx_output.Text = ((Button)sender).Content.ToString();
                    del = false;
                }
            }
        }

        private void Comma(object sender, RoutedEventArgs e)
        {
            try
            {
                if (tx_output.Text == "" || del == true)
                {
                    tx_output.Text = "0.";
                    del = false;
                }
                else if (Convert.ToInt32(tx_output.Text) % 1 == 0) tx_output.Text += ".";
            }
            catch
            {

            }
        }

        private void PlusMinus(object sender, RoutedEventArgs e)
        {
            try
            {
                if (tx_output.Text != "")
                {
                    if (Convert.ToDouble(tx_output.Text) > 0) tx_output.Text = "-" + tx_output.Text;
                    else if (Convert.ToDouble(tx_output.Text) < 0) tx_output.Text = tx_output.Text.Remove(0, 1);
                }
            }
            catch
            {

            }
        }

        private void Conversion(object sender, PointerRoutedEventArgs e)
        {
            if (((TextBlock)sender).Text == "DEC") to = 10;
            else if (((TextBlock)sender).Text == "BIN") to = 2;
            else if (((TextBlock)sender).Text == "OCT") to = 8;
            else if (((TextBlock)sender).Text == "HEX") to = 16;

            try
            {
                if (tx_output.Text != "") tx_output.Text = Convert.ToString(Convert.ToInt32(tx_output.Text, from), to);

                if (((TextBlock)sender).Text == "DEC") tb_dec.Foreground = new SolidColorBrush(SmurfetBlue);
                else tb_dec.Foreground = new SolidColorBrush(Colors.White);

                if (((TextBlock)sender).Text == "BIN") tb_bin.Foreground = new SolidColorBrush(SmurfetBlue);
                else tb_bin.Foreground = new SolidColorBrush(Colors.White);

                if (((TextBlock)sender).Text == "OCT") tb_oct.Foreground = new SolidColorBrush(SmurfetBlue);
                else tb_oct.Foreground = new SolidColorBrush(Colors.White);

                if (((TextBlock)sender).Text == "HEX") tb_hex.Foreground = new SolidColorBrush(SmurfetBlue);
                else tb_hex.Foreground = new SolidColorBrush(Colors.White);

                if (to == 10) bt_comma.IsEnabled = true;
                else bt_comma.IsEnabled = false;

                if (to == 10 || to == 8 || to == 16)
                {
                    bt_2.IsEnabled = true;
                    bt_3.IsEnabled = true;
                    bt_4.IsEnabled = true;
                    bt_5.IsEnabled = true;
                    bt_6.IsEnabled = true;
                    bt_7.IsEnabled = true;
                }
                else
                {
                    bt_2.IsEnabled = false;
                    bt_3.IsEnabled = false;
                    bt_4.IsEnabled = false;
                    bt_5.IsEnabled = false;
                    bt_6.IsEnabled = false;
                    bt_7.IsEnabled = false;
                }

                if (to == 10 || to == 16)
                {
                    bt_8.IsEnabled = true;
                    bt_9.IsEnabled = true;
                }
                else
                {
                    bt_8.IsEnabled = false;
                    bt_9.IsEnabled = false;
                }

                if (to == 16) gr_chars.Visibility = Visibility.Visible;
                else gr_chars.Visibility = Visibility.Collapsed;

                from = to;
            }
            catch
            {
                Universal.Error(1);
            }
            Universal.error = false;
        }

        private void LoadIn()
        {
            try
            {
                if (from == 10)
                {
                    if (op != "xⁿ") x = Convert.ToDouble(tx_output.Text);
                    else y = Convert.ToDouble(tx_output.Text);
                }
                else
                {
                    if (op != "xⁿ") x = Convert.ToDouble(Convert.ToString(Convert.ToInt32(tx_output.Text, from), 10));
                    else y = Convert.ToDouble(Convert.ToString(Convert.ToInt32(tx_output.Text, from), 10));
                }

                tx_output.Text = "";
            }
            catch
            {
                Universal.Error(1);
            }
        }

        private void Calc()
        {
            if (op == "+") v += x;
            else if (op == "-") v -= x;
            else if (op == "*") v *= x;
            else if (op == "/")
            {
                if (x == 0) Universal.Error(2);
                else v /= x;
            }
            else if (op == "xⁿ")
            {
                x = v;
                v = Math.Pow(x, y);
            }
        }

        private void PrintOut()
        {
            if (Universal.error == false)
            {
                if (from == 10) tx_output.Text = v.ToString();
                else tx_output.Text = Convert.ToString(Convert.ToInt32(v.ToString(), 10), to);
            }
            else ClearAll();
        }

        private void Operation(object sender, RoutedEventArgs e)
        {
            if (tx_output.Text != "")
            {
                LoadIn();

                if (op == "") v = x;
                else
                {
                    Calc();
                    PrintOut();
                    if (Universal.error == false) del = true;
                }
            }
            if (Universal.error == false) op = ((Button)sender).Content.ToString();
            Universal.error = false;
        }

        private void Maths(object sender, RoutedEventArgs e)
        {
            if (tx_output.Text != "")
            {
                LoadIn();

                if (op != "" && op != "x²" && op != "√x")
                {
                    Calc();
                    x = v;
                }

                if (Universal.error == false)
                {
                    op = ((Button)sender).Content.ToString();

                    if (op == "x²") v = Math.Pow(x, 2);
                    else if (op == "√x" && x >= 0) v = Math.Sqrt(x);
                    else Universal.Error(5);
                }
                PrintOut();
            }
            Universal.error = false;
        }

        private void Result(object sender, RoutedEventArgs e)
        {
            if (tx_output.Text != "" && op != "")
            {
                LoadIn();
                Calc();
                PrintOut();
                op = "";
            }
            Universal.error = false;
        }

        private void Hamburger(object sender, RoutedEventArgs e)
        {
            if (gr_menu.Visibility == Visibility.Collapsed) gr_menu.Visibility = Visibility.Visible;
            else gr_menu.Visibility = Visibility.Collapsed;
        }

        private void Goto(object sender, RoutedEventArgs e)
        {
            Universal.conv = ((Button)sender).Content.ToString();

            if (((Button)sender).Content.ToString() == "Pythagorean theorem") this.Frame.Navigate(typeof(Pythg));
            else this.Frame.Navigate(typeof(Conversions));
        }

        private void MemAdd(object sender, RoutedEventArgs e)
        {
            if (tx_output.Text != "")
            {
                Universal.memory[0] = tx_output.Text;
                Universal.memory[1] = from.ToString();
                tx_memory.Text = Universal.memory[0];
            }
        }

        private void MemRead(object sender, RoutedEventArgs e)
        {
            if (Universal.memory[0] != "" && Convert.ToInt16(Universal.memory[1]) == from) tx_output.Text = Universal.memory[0];
            else Universal.Error(4);
        }

        private void MemDel(object sender, RoutedEventArgs e)
        {
            Universal.memory[0] = "";
            Universal.memory[1] = "";
            tx_memory.Text = Universal.memory[0];
        }

        private void MenuHold(object sender, RoutedEventArgs e)
        {
            Universal.menuhold = Convert.ToBoolean(ch_menuhold.IsChecked);
        }

        private void Responsive(object sender, SizeChangedEventArgs e)
        {
            if (((Page)sender).ActualWidth <= 1000) cd_maincenter.Width = new GridLength(10, GridUnitType.Star);
            else if (((Page)sender).ActualWidth > 1000 && ((Page)sender).ActualWidth <= 1400) cd_maincenter.Width = new GridLength(5, GridUnitType.Star);
            else cd_maincenter.Width = new GridLength(2, GridUnitType.Star);

            if (((Page)sender).ActualWidth <= 700) cd_systembig.Width = new GridLength(0, GridUnitType.Star);
            else if (((Page)sender).ActualWidth > 700 && ((Page)sender).ActualWidth <= 1400) cd_systembig.Width = new GridLength(5, GridUnitType.Star);
            else cd_systembig.Width = new GridLength(8, GridUnitType.Star);
        }
    }
}
