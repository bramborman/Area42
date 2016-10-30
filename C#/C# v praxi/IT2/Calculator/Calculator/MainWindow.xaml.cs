using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Calculator
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void bt_calc_Click(object sender, RoutedEventArgs e)
        {
            double a, b, c, D, x1, x2;

            try
            {
                if (tx_a.Text == "")
                {
                    tx_a.Text = "0";
                }

                if (tx_b.Text == "")
                {
                    tx_b.Text = "0";
                }

                if (tx_c.Text == "")
                {
                    tx_c.Text = "0";
                }

                a = Convert.ToDouble(tx_a.Text);
                b = Convert.ToDouble(tx_b.Text);
                c = Convert.ToDouble(tx_c.Text);

                D = b * b -4 * a * c;

                if (D > 0)
                {
                    x1 = (-b + Math.Sqrt(D)) / 2 * a;
                    x2 = (-b - Math.Sqrt(D)) / 2 * a;

                    lb_result.Content = "x1=" + x1 + "\nx2=" + x2;
                }
                else if (D == 0)
                {
                    x1 = -(b / 2 * a);

                    lb_result.Content = "x=" + x1;
                }
                else
                {
                    lb_result.Content = "Has no result!";
                }
            }
            catch
            {
                MessageBox.Show(string.Format("Wrong input is entered!"), "Wrong input!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
    }
}
