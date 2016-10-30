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

namespace Modern_Calculator
{
    /// <summary>
    /// Pythagorean theorem.
    /// </summary>
    public sealed partial class Pythg : Page
    {
        public Pythg()
        {
            this.InitializeComponent();

            if (Universal.menuhold == true) gr_menu.Visibility = Visibility.Visible;
            ch_menuhold.IsChecked = Universal.menuhold;

            tx_memory.Text = Universal.memory[0];
        }

        Double s1 = 0, s2 = 0, v = 0;
        String focus = "tx_side1";

        private void ClearAll()
        {
            s1 = 0;
            s2 = 0;
            v = 0;

            tx_side1.Text = "";
            tx_side2.Text = "";
            tx_ch.Text = "";
            tx_side3.Text = "";

            Universal.error = false;
        }

        private void Clear(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "AC") ClearAll();
            else if (((Button)sender).Content.ToString() == "←" && focus != "tx_side3" && ((TextBox)this.FindName(focus)).Text != "")
            {
                ((TextBox)this.FindName(focus)).Text = ((TextBox)this.FindName(focus)).Text.Remove(((TextBox)this.FindName(focus)).Text.Length - 1, 1);
            }
        }

        private void Add(object sender, RoutedEventArgs e)
        {
            if (focus != "tx_side3" && ((TextBox)this.FindName(focus)).Text != "0") ((TextBox)this.FindName(focus)).Text += ((Button)sender).Content.ToString();
        }

        private void Comma(object sender, RoutedEventArgs e)
        {
            try
            {
                if (focus != "tx_side3")
                {
                    if (((TextBox)this.FindName(focus)).Text == "") ((TextBox)this.FindName(focus)).Text = "0.";
                    else if (Convert.ToInt32(((TextBox)this.FindName(focus)).Text) % 1 == 0) ((TextBox)this.FindName(focus)).Text += ".";
                }
            }
            catch
            {

            }
        }

        private void Duplicate(object sender, object e)
        {
            /*for (Char dupl = 'a'; dupl <= 'c'; dupl++)
            {
                if (((ComboBoxItem)this.FindName("ci_" + dupl + "1")).IsSelected == true)
                {
                    if (((ComboBoxItem)this.FindName("ci_" + dupl + "2")).IsSelected == true) ((ComboBoxItem)this.FindName("ci_" + dupl + "2")).IsSelected = false;

                    ((ComboBoxItem)this.FindName("ci_" + dupl + "2")).Visibility = Visibility.Collapsed;

                    if (dupl != 'a') ci_a2.Visibility = Visibility.Visible;
                    if (dupl != 'b') ci_b2.Visibility = Visibility.Visible;
                    if (dupl != 'c') ci_c2.Visibility = Visibility.Visible;
                }
            }*/
            
            if (ci_a1.IsSelected == true)
            {
                if (ci_a2.IsSelected == true) ci_a2.IsSelected = false;
                ci_a2.Visibility = Visibility.Collapsed;
            }
            else ci_a2.Visibility = Visibility.Visible;

            if (ci_b1.IsSelected == true)
            {
                if (ci_b2.IsSelected == true) ci_b2.IsSelected = false;
                ci_b2.Visibility = Visibility.Collapsed;
            }
            else ci_b2.Visibility = Visibility.Visible;

            if (ci_c1.IsSelected == true)
            {
                if (ci_c2.IsSelected == true) ci_c2.IsSelected = false;
                ci_c2.Visibility = Visibility.Collapsed;
            }
            else ci_c2.Visibility = Visibility.Visible;
        }

        private void Result(object sender, RoutedEventArgs e)
        {
            if (tx_side1.Text != "" && tx_side2.Text != "")
            {
                try
                {
                    s1 = Convert.ToDouble(tx_side1.Text);
                    s2 = Convert.ToDouble(tx_side2.Text);
                    tx_side3.Text = "";

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

                    if (Universal.error == false) tx_side3.Text = v.ToString();
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

        private void Goto(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "Calculator") this.Frame.Navigate(typeof(MainPage));
            else this.Frame.Navigate(typeof(Conversions));
        }

        private void Focus(object sender, RoutedEventArgs e)
        {
            focus = ((TextBox)sender).Name;
        }

        private void MemAdd(object sender, RoutedEventArgs e)
        {
            if (((TextBox)this.FindName(focus)).Text != "" && ((TextBox)this.FindName(focus)).Text != "NaN")
            {
                Universal.memory[0] = ((TextBox)this.FindName(focus)).Text;
                Universal.memory[1] = "10";
                tx_memory.Text = Universal.memory[0];
            }
        }

        private void MemRead(object sender, RoutedEventArgs e)
        {
            if (Universal.memory[0] != "" && Universal.memory[1] == "10" && focus != "tx_side3") ((TextBox)this.FindName(focus)).Text = Universal.memory[0];
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

            if (((Page)sender).ActualWidth <= 750) cd_textboxes.Width = new GridLength(4, GridUnitType.Star);
            else cd_textboxes.Width = new GridLength(7, GridUnitType.Star);
        }
    }
}
