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

namespace DÚ_01_Kalkulačka2
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class Prevody : Page
    {
        public Prevody()
        {
            this.InitializeComponent();
        }

        String prohodit1, prohodit2;
        int prevod = 0, v = 0;

        private void pocitat(object sender, RoutedEventArgs e)
        {
            //prevod = Convert.ToDouble(tx_prevod1.Text);
            int.TryParse(tx_prevod1.Text, out prevod);

            if(ci_dec1.IsSelected == true)
            {
                if(ci_dec2.IsSelected == true)
                {
                    tx_prevod2.Text = tx_prevod1.Text;
                }
                else if(ci_bin2.IsSelected == true)
                {
                    tx_prevod2.Text = Convert.ToString(prevod, 2);
                }
                else if(ci_oct2.IsSelected == true)
                {
                    tx_prevod2.Text = Convert.ToString(prevod, 8);
                }
                else if (ci_oct2.IsSelected == true)
                {
                    tx_prevod2.Text = Convert.ToString(prevod, 16);
                }
            }

            else if (ci_bin1.IsSelected == true)
            {
                v = prevod;
                
                tx_prevod2.Text = Convert.ToString(prevod, 2);
            }
        }

        private void prohodit(object sender, RoutedEventArgs e)
        {
            prohodit1 = tx_prevod1.Text;
            prohodit2 = tx_prevod2.Text;
            tx_prevod1.Text = prohodit2;
            tx_prevod2.Text = prohodit1;
        }

        private void Goto_Main(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(MainPage));
        }
    }
}
