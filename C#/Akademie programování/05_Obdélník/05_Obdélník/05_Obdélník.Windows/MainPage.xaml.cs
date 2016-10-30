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

namespace _05_Obdélník
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        double d, v, s, o;


        private void obvod(object sender, RoutedEventArgs e)
        {
            d = Convert.ToDouble(tx_delka.Text);
            v = Convert.ToDouble(tx_vyska.Text);
            o = d + d + v + v;
            g_obvod.Visibility = Visibility.Visible;
            tb_obvod.Text = "o =" + o.ToString() + "cm";
        }

        private void obsah(object sender, RoutedEventArgs e)
        {
            d = Convert.ToDouble(tx_delka.Text);
            v = Convert.ToDouble(tx_vyska.Text);
            s = d * v;
            tb_obsah.Text = "S = " + s.ToString() + "cm2";
        }
    }
}
