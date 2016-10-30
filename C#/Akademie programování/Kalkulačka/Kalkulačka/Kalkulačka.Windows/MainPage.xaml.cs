using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace Kalkulačka
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();

            if (Universal.menuhold == true)
            {
                gr_menu.Visibility = Visibility.Visible;
                ch_menuhold.IsChecked = true;
            }

            tx_memory.Text = Universal.memory;
        }

        bool del = false;
        double x = 0, y = 0, v = 0;
        String op = "";

        private void ClearAll()
        {
            del = false;
            x = 0;
            y = 0;
            v = 0;
            op = "";

            tx_vypis.Text = "";

            Universal.error = false;
        }

        private void Clear(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "C") tx_vypis.Text = "";
            else if (((Button)sender).Content.ToString() == "CE") ClearAll();
            else if (((Button)sender).Content.ToString() == "←")
            {
                if (tx_vypis.Text != "")
                {
                    tx_vypis.Text = tx_vypis.Text.Remove(tx_vypis.Text.Length - 1, 1);
                }
            }
        }

        private void Add(object sender, RoutedEventArgs e)
        {
            if (del == false) tx_vypis.Text += ((Button)sender).Content.ToString();
            else
            {
                tx_vypis.Text = ((Button)sender).Content.ToString();
                del = false;
            }
        }

        private void Comma(object sender, RoutedEventArgs e)
        {
            if (tx_vypis.Text == "") tx_vypis.Text = "0,";
            else if (Convert.ToDouble(tx_vypis.Text)%1 == 0)
            {
                if (del == false) tx_vypis.Text += ",";
                else
                {
                    tx_vypis.Text = "0,";
                    del = false;
                }
            }
        }

        private void PlusMinus(object sender, RoutedEventArgs e)
        {
            if (tx_vypis.Text != "")
            {
                if (Convert.ToDouble(tx_vypis.Text) > 0) tx_vypis.Text = "-" + tx_vypis.Text;
                else if (Convert.ToDouble(tx_vypis.Text) < 0) tx_vypis.Text = tx_vypis.Text.Remove(0, 1);
            }
        }

        private void Operation(object sender, RoutedEventArgs e)
        {
            if (tx_vypis.Text != "")
            {
                try
                {
                    if (op != "xⁿ") x = Convert.ToDouble(tx_vypis.Text);
                    else y = Convert.ToDouble(tx_vypis.Text);
                    tx_vypis.Text = "";

                    if (op == "") v = x;
                    else
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

                        if (Universal.error == false)
                        {
                            tx_vypis.Text = v.ToString();
                            del = true;
                        }
                        else ClearAll();
                    }
                }
                catch
                {
                    Universal.Error(1);
                }
            }
            op = ((Button)sender).Content.ToString();
            Universal.error = false;
        }

        private void Maths(object sender, RoutedEventArgs e)
        {
            if (tx_vypis.Text != "")
            {
                try
                {
                    if (op != "xⁿ") x = Convert.ToDouble(tx_vypis.Text);
                    else y = Convert.ToDouble(tx_vypis.Text);
                    tx_vypis.Text = "";

                    if (op != "" && op != "x²" && op != "√x")
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
                        x = v;
                    }

                    if (Universal.error == false)
                    {
                        op = ((Button)sender).Content.ToString();

                        if (op == "x²") v = Math.Pow(x, 2);
                        else if (op == "√x") v = Math.Sqrt(x);

                        tx_vypis.Text = v.ToString();
                    }
                    else ClearAll();
                    
                }
                catch
                {
                    Universal.Error(1);
                }
            }
            Universal.error = false;
        }

        private void Calc(object sender, RoutedEventArgs e)
        {
            if (tx_vypis.Text != "" && op != "")
            {
                try
                {
                    if (op != "xⁿ") x = Convert.ToDouble(tx_vypis.Text);
                    else y = Convert.ToDouble(tx_vypis.Text);
                    tx_vypis.Text = "";

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

                    if (Universal.error == false) tx_vypis.Text = v.ToString();
                    else ClearAll();

                    op = "";
                }
                catch
                {
                    Universal.Error(1);
                }
            }
            Universal.error = false;
        }
        
        private void Hamburger(object sender, RoutedEventArgs e)
        {
            if (gr_menu.Visibility == Visibility.Collapsed) gr_menu.Visibility = Visibility.Visible;
            else gr_menu.Visibility = Visibility.Collapsed;
        }

        private void GotoPrevody(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(Prevody));
        }

        private void GotoPythg(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(Pythg));
        }

        private void MemAdd(object sender, RoutedEventArgs e)
        {
            if (tx_vypis.Text != "")
            {
                Universal.memory = tx_vypis.Text;
                tx_memory.Text = Universal.memory;
            }
        }

        private void MemRead(object sender, RoutedEventArgs e)
        {
            try
            {
                if (Universal.memory != "" && Convert.ToDouble(Universal.memory) % 1 == 0) tx_vypis.Text = Universal.memory;
            }
            catch
            {
                Universal.Error(4);
            }
        }

        private void MemDel(object sender, RoutedEventArgs e)
        {
            Universal.memory = "";
            tx_memory.Text = Universal.memory;
        }

        private void MenuHold(object sender, RoutedEventArgs e)
        {
            if (ch_menuhold.IsChecked == true) Universal.menuhold = true;
            else Universal.menuhold = false;
        }
    }
}
