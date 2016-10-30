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

namespace DÚ_01_Kalkulačka
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

        int op = 1, c1 = 0, c2 = 0, vysl = 0;

        private void plus(object sender, RoutedEventArgs e)
        {
            tb_op.Text = "+";
            op = 1;
        }

        private void minus(object sender, RoutedEventArgs e)
        {

            tb_op.Text = "-";
            op = 2;
        }

        private void krat(object sender, RoutedEventArgs e)
        {

            tb_op.Text = "x";
            op = 3;
        }

        private void deleno(object sender, RoutedEventArgs e)
        {

            tb_op.Text = ":";
            op = 4;
        }

        private void mocnit(object sender, RoutedEventArgs e)
        {

            tb_op.Text = "˄";
            op = 1;
        }

        private void vys(object sender, RoutedEventArgs e)
        {
            c1 = Int32.Parse(tx_c1.Text);
            c2 = Int32.Parse(tx_c2.Text);

            if (op == 1)
            {
                vysl = c1 + c2;
                
            }

            tb_vys.Text = vysl.ToString();
        }
    }
}
