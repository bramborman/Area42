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
    public sealed partial class Prevody : Page
    {
        public Prevody()
        {
            this.InitializeComponent();

            if (Universal.menuhold == true)
            {
                gr_menu.Visibility = Visibility.Visible;
                ch_menuhold.IsChecked = true;
            }

            tx_memory.Text = Universal.memory;
        }

        int from = 0, to = 0;
        String change = "", focus = "tx_vstup";

        private void ClearAll()
        {
            from = 0;
            to = 0;
            change = "";

            tx_vstup.Text = "";
            tx_vypis.Text = "";

            Universal.error = false;
        }

        private void Clear(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "CE") ClearAll();
            else if (((Button)sender).Content.ToString() == "←" && tx_vstup.Text != "")
            {
                tx_vstup.Text = tx_vstup.Text.Remove(tx_vstup.Text.Length - 1, 1);
            }
        }

        private void Add(object sender, RoutedEventArgs e)
        {
            tx_vstup.Text += ((Button)sender).Content.ToString();
        }

        private void PlusMinus(object sender, RoutedEventArgs e)
        {
            if (tx_vstup.Text != "")
            {
                if (Convert.ToDouble(tx_vstup.Text) > 0) tx_vstup.Text = "-" + tx_vstup.Text;
                else if (Convert.ToDouble(tx_vstup.Text) < 0) tx_vstup.Text = tx_vstup.Text.Remove(0, 1);
            }
        }

        private void Change(object sender, RoutedEventArgs e)
        {
            change = tx_vstup.Text;
            tx_vstup.Text = tx_vypis.Text;
            tx_vypis.Text = change;
        }

        private void Calc(object sender, RoutedEventArgs e)
        {
            if (ci_dec1.IsSelected == true) from = 10;
            else if (ci_bin1.IsSelected == true) from = 2;
            else if (ci_oct1.IsSelected == true) from = 8;
            else if (ci_hex1.IsSelected == true) from = 16;

            if (ci_dec2.IsSelected == true) to = 10;
            else if (ci_bin2.IsSelected == true) to = 2;
            else if (ci_oct2.IsSelected == true) to = 8;
            else if (ci_hex2.IsSelected == true) to = 16;

            if (tx_vstup.Text != "")
            {
                try
                {
                    tx_vypis.Text = Convert.ToString(Convert.ToInt32(tx_vstup.Text, from), to);
                }
                catch
                {
                    Universal.Error(1);
                }
            }
        }

        private void KeyFilter(object sender, object e)
        {
            if (ci_dec1.IsSelected == true)
            {
                bt_pm.IsEnabled = true;

                bt_2.IsEnabled = true;
                bt_3.IsEnabled = true;
                bt_4.IsEnabled = true;
                bt_5.IsEnabled = true;
                bt_6.IsEnabled = true;
                bt_7.IsEnabled = true;
                bt_8.IsEnabled = true;
                bt_9.IsEnabled = true;

                bt_a.IsEnabled = false;
                bt_b.IsEnabled = false;
                bt_c.IsEnabled = false;
                bt_d.IsEnabled = false;
                bt_e.IsEnabled = false;
                bt_f.IsEnabled = false;
            }
            else if (ci_bin1.IsSelected == true)
            {
                bt_pm.IsEnabled = false;

                bt_2.IsEnabled = false;
                bt_3.IsEnabled = false;
                bt_4.IsEnabled = false;
                bt_5.IsEnabled = false;
                bt_6.IsEnabled = false;
                bt_7.IsEnabled = false;
                bt_8.IsEnabled = false;
                bt_9.IsEnabled = false;

                bt_a.IsEnabled = false;
                bt_b.IsEnabled = false;
                bt_c.IsEnabled = false;
                bt_d.IsEnabled = false;
                bt_e.IsEnabled = false;
                bt_f.IsEnabled = false;
            }
            else if (ci_oct1.IsSelected == true)
            {
                bt_pm.IsEnabled = false;

                bt_2.IsEnabled = true;
                bt_3.IsEnabled = true;
                bt_4.IsEnabled = true;
                bt_5.IsEnabled = true;
                bt_6.IsEnabled = true;
                bt_7.IsEnabled = true;
                bt_8.IsEnabled = false;
                bt_9.IsEnabled = false;

                bt_a.IsEnabled = false;
                bt_b.IsEnabled = false;
                bt_c.IsEnabled = false;
                bt_d.IsEnabled = false;
                bt_e.IsEnabled = false;
                bt_f.IsEnabled = false;
            }
            else if (ci_hex1.IsSelected == true)
            {
                bt_pm.IsEnabled = false;

                bt_2.IsEnabled = true;
                bt_3.IsEnabled = true;
                bt_4.IsEnabled = true;
                bt_5.IsEnabled = true;
                bt_6.IsEnabled = true;
                bt_7.IsEnabled = true;
                bt_8.IsEnabled = true;
                bt_9.IsEnabled = true;

                bt_a.IsEnabled = true;
                bt_b.IsEnabled = true;
                bt_c.IsEnabled = true;
                bt_d.IsEnabled = true;
                bt_e.IsEnabled = true;
                bt_f.IsEnabled = true;
            }
        }

        private void Hamburger(object sender, RoutedEventArgs e)
        {
            if (gr_menu.Visibility == Visibility.Collapsed) gr_menu.Visibility = Visibility.Visible;
            else gr_menu.Visibility = Visibility.Collapsed;
        }

        private void GotoMain(object sender, RoutedEventArgs e)
        {
            Frame.Navigate(typeof(MainPage));
        }

        private void GotoPythg(object sender, RoutedEventArgs e)
        {
            Frame.Navigate(typeof(Pythg));
        }

        private void Focus(object sender, RoutedEventArgs e)
        {
            focus = ((TextBox)sender).Name;
        }

        private void MemAdd(object sender, RoutedEventArgs e)
        {
            if (((TextBox)this.FindName(focus)).Text != "")
            {
                Universal.memory = ((TextBox)this.FindName(focus)).Text;
                tx_memory.Text = Universal.memory;
            }
        }

        private void MemRead(object sender, RoutedEventArgs e)
        {
            if (Universal.memory != "") tx_vstup.Text = Universal.memory;
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
