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
    public sealed partial class Pythg : Page
    {
        public Pythg()
        {
            this.InitializeComponent();

            if (Universal.menuhold == true)
            {
                gr_menu.Visibility = Visibility.Visible;
                ch_menuhold.IsChecked = true;
            }

            tx_memory.Text = Universal.memory;
        }

        double s1 = 0, s2 = 0, v = 0;
        String focus = "tx_strana1";

        private void ClearAll()
        {
            s1 = 0;
            s2 = 0;
            v = 0;

            tx_strana1.Text = "";
            tx_strana2.Text = "";
            tx_ch.Text = "";
            tx_strana3.Text = "";

            Universal.error = false;
        }

        private void Clear(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "CE") ClearAll();
            else if (((Button)sender).Content.ToString() == "←" && focus != "tx_strana3" && ((TextBox)this.FindName(focus)).Text != "")
            {
                ((TextBox)this.FindName(focus)).Text = ((TextBox)this.FindName(focus)).Text.Remove(((TextBox)this.FindName(focus)).Text.Length - 1, 1);
            }
        }

        private void Add(object sender, RoutedEventArgs e)
        {
            if (focus != "tx_strana3") ((TextBox)this.FindName(focus)).Text += ((Button)sender).Content.ToString();
        }

        private void Comma(object sender, RoutedEventArgs e)
        {
            if (focus != "tx_strana3")
            {
                if (((TextBox)this.FindName(focus)).Text == "") ((TextBox)this.FindName(focus)).Text = "0,";
                else if (Convert.ToDouble(((TextBox)this.FindName(focus)).Text) % 1 == 0) ((TextBox)this.FindName(focus)).Text += ",";
            }
        }

        private void Calc(object sender, RoutedEventArgs e)
        {
            if (tx_strana1.Text != "" && tx_strana2.Text != "")
            {
                try
                {
                    s1 = Convert.ToDouble(tx_strana1.Text);
                    s2 = Convert.ToDouble(tx_strana2.Text);
                    tx_strana3.Text = "";
                }
                catch
                {
                    Universal.Error(1);
                }

                if ((ci_a1.IsSelected == true && ci_b2.IsSelected == true) || (ci_b1.IsSelected == true && ci_a2.IsSelected == true))
                {
                    v = Math.Sqrt(s1 * s1 + s2 * s2);
                    tx_ch.Text = ":c";
                }
                else if ((ci_a1.IsSelected == true || ci_b1.IsSelected == true) && ci_c2.IsSelected == true)
                {
                    v = Math.Sqrt(s2 * s2 - s1 * s1);
                    if (ci_a1.IsSelected == true) tx_ch.Text = ":b";
                    else if (ci_b1.IsSelected == true) tx_ch.Text = ":a";
                }
                else if (ci_c1.IsSelected == true && (ci_a2.IsSelected == true || ci_b2.IsSelected == true))
                {
                    v = Math.Sqrt(s1 * s1 - s2 * s2);
                    if (ci_a2.IsSelected == true) tx_ch.Text = ":b";
                    else if (ci_b2.IsSelected == true) tx_ch.Text = ":a";
                }
                else
                {
                    tx_ch.Text = "";
                    Universal.Error(3);
                }

                if (Universal.error == false) tx_strana3.Text = v.ToString();
            }
            Universal.error = false;
        }

        private void Duplicate(object sender, object e)
        {
            if (ci_a1.IsSelected == true)
            {
                if (ci_a2.IsSelected == true) ci_a2.IsSelected = false;

                ci_a2.Visibility = Visibility.Collapsed;
                ci_b2.Visibility = Visibility.Visible;
                ci_c2.Visibility = Visibility.Visible;
            }
            else if (ci_b1.IsSelected == true)
            {
                if (ci_b2.IsSelected == true) ci_b2.IsSelected = false;

                ci_a2.Visibility = Visibility.Visible;
                ci_b2.Visibility = Visibility.Collapsed;
                ci_c2.Visibility = Visibility.Visible;
            }
            else if (ci_c1.IsSelected == true)
            {
                if (ci_c2.IsSelected == true) ci_c2.IsSelected = false;

                ci_a2.Visibility = Visibility.Visible;
                ci_b2.Visibility = Visibility.Visible;
                ci_c2.Visibility = Visibility.Collapsed;
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

        private void GotoPrevody(object sender, RoutedEventArgs e)
        {
            Frame.Navigate(typeof(Prevody));
        }

        private void Focus(object sender, RoutedEventArgs e)
        {
            focus = ((TextBox)sender).Name;
        }

        private void MemAdd(object sender, RoutedEventArgs e)
        {
            if (((TextBox)this.FindName(focus)).Text != "" && ((TextBox)this.FindName(focus)).Text != "Není číslo")
            {
                Universal.memory = ((TextBox)this.FindName(focus)).Text;
                tx_memory.Text = Universal.memory;
            }
        }

        private void MemRead(object sender, RoutedEventArgs e)
        {
            try
            {
                if (Universal.memory != "" && Convert.ToDouble(Universal.memory) % 1 == 0 && focus != "tx_strana3") ((TextBox)this.FindName(focus)).Text = Universal.memory;
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
