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
    /// Conversions.
    /// </summary>
    public sealed partial class Conversions : Page
    {
        public Conversions()
        {
            this.InitializeComponent();

            if (Universal.menuhold == true) gr_menu.Visibility = Visibility.Visible;
            ch_menuhold.IsChecked = Universal.menuhold;

            tx_memory.Text = Universal.memory[0];

            Filter();
        }

        Int16 from = 0, to = 0;
        String change = "", focus = "tx_input";

        private void ClearAll()
        {
            change = "";

            tx_input.Text = "";
            tx_output.Text = "";

            Universal.error = false;
        }

        private void Filter()
        {
            if (Universal.conv == "Length")
            {
                ci_m9.Content = "nanometers";
                ci_m6.Content = "micrometers";
                ci_m5.Visibility = Visibility.Collapsed;
                ci_m4.Visibility = Visibility.Collapsed;
                ci_m3.Content = "milimeters";
                ci_m2.Content = "centimeters";
                ci_m1.Content = "decimeters";
                ci_0.Content = "meters";
                ci_1.Visibility = Visibility.Collapsed;
                ci_2.Visibility = Visibility.Collapsed;
                ci_3.Content = "kilometers";
                ci_4.Visibility = Visibility.Collapsed;
                ci_5.Visibility = Visibility.Collapsed;
            }
        }

        private void Clear(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "AC") ClearAll();
            else if (((Button)sender).Content.ToString() == "←" && tx_input.Text != "") tx_input.Text = tx_input.Text.Remove(tx_input.Text.Length - 1, 1);
        }

        private void Add(object sender, RoutedEventArgs e)
        {
            if (tx_input.Text != "0") tx_input.Text += ((Button)sender).Content.ToString();
        }

        private void Comma(object sender, RoutedEventArgs e)
        {
            try
            {
                if (tx_input.Text == "") tx_input.Text = "0.";
                else if (Convert.ToInt32(tx_input.Text) % 1 == 0) tx_input.Text += ".";
            }
            catch
            {

            }
        }

        private void Change(object sender, RoutedEventArgs e)
        {
            if (tx_input.Text != "" && tx_output.Text != "")
            {
                change = tx_input.Text;
                tx_input.Text = tx_output.Text;
                tx_output.Text = change;
            }
        }

        private void PointerReleased(object sender, PointerRoutedEventArgs e)
        {
            try
            {
                from = Convert.ToInt16(((ComboBoxItem)sender).Name.ToString().Remove(((ComboBoxItem)sender).Name.ToString().Length - 1, 3));
                tx_output.Text = from.ToString();
            }
            catch
            {
                Universal.Error(0);
            }
        }

        private void Result(object sender, RoutedEventArgs e)
        {
            
        }

        private void Hamburger(object sender, RoutedEventArgs e)
        {
            if (gr_menu.Visibility == Visibility.Collapsed) gr_menu.Visibility = Visibility.Visible;
            else gr_menu.Visibility = Visibility.Collapsed;
        }

        private void Goto(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "Calculator") this.Frame.Navigate(typeof(MainPage));
            else if (((Button)sender).Content.ToString() == "Pythagorean theorem") this.Frame.Navigate(typeof(Pythg));
        }

        private void Focus(object sender, RoutedEventArgs e)
        {
            focus = ((TextBox)sender).Name;
        }

        private void MemAdd(object sender, RoutedEventArgs e)
        {
            if (((TextBox)this.FindName(focus)).Text != "")
            {
                Universal.memory[0] = ((TextBox)this.FindName(focus)).Text;
                Universal.memory[1] = "10";
                tx_memory.Text = Universal.memory[0];
            }
        }

        private void MemRead(object sender, RoutedEventArgs e)
        {
            if (Universal.memory[0] != "" && Universal.memory[1] == "10") tx_input.Text = Universal.memory[0];
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
    }
}
