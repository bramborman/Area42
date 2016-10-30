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
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        String vypis;
        int op = 0, odc = 0, nas = 0, del = 0, p = 0, moc = 0, vysc = 0;
        double c = 0, x = 0, vys = 0;

        private void nula(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "0";
        }

        private void clear(object sender, RoutedEventArgs e)
        {
            tx_vypis.Text = "";
        }

        private void clearall(object sender, RoutedEventArgs e)
        {
            tx_vypis.Text = "";
            c = 0;
            x = 0;
            vys = 0;
            op = 0;
            odc = 0;
            nas = 0;
            del = 0;
            p = 0;
            moc = 0;
            vysc = 0;
        }

        private void jedna(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "1";
        }

        private void dva(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "2";
        }

        private void tri(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "3";
        }

        private void ctyri(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "4";
        }

        private void pet(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "5";
        }

        private void sest(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "6";
        }

        private void sedm(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "7";
        }

        private void osm(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "8";
        }

        private void devet(object sender, RoutedEventArgs e)
        {
            vypis = tx_vypis.Text;
            tx_vypis.Text = vypis + "9";
        }

        private void plus(object sender, RoutedEventArgs e)
        {
            op = 1;
            if(vysc == 0)
            {
                c = Convert.ToDouble(tx_vypis.Text);
                vys += c;
            }
            else
            {

            }

            tx_vypis.Text = "";
            vysc = 0;
        }

        private void minus(object sender, RoutedEventArgs e)
        {
            op = 2;
            if (vysc == 0)
            {
                c = Convert.ToDouble(tx_vypis.Text);
                if (odc == 0)
                {
                    vys = c;
                }

                else
                {
                    vys -= c;
                }
            }

            tx_vypis.Text = "";
            odc++;
            vysc = 0;
        }

        private void krat(object sender, RoutedEventArgs e)
        {
            op = 3;
            if (vysc == 0)
            {
                c = Convert.ToDouble(tx_vypis.Text);
                if (nas == 0)
                {
                    vys = 1;
                }
                vys *= c;
            }

            tx_vypis.Text = "";
            nas++;
            vysc = 0;
        }

        private void deleno(object sender, RoutedEventArgs e)
        {
            op = 4;
            if (vysc == 0)
            {
                c = Convert.ToDouble(tx_vypis.Text);
                if (del == 0)
                {
                    vys = c;
                }
                else
                {
                    if (c == 0)
                    {
                        p = 1;
                    }
                    else
                    {
                        vys /= c;
                    }
                }
            }
            tx_vypis.Text = "";
            del++;
            vysc = 0;
        }

        private void mocnit2(object sender, RoutedEventArgs e)
        {
            op = 5;
            c = Convert.ToDouble(tx_vypis.Text);
            vys = Math.Pow(c, 2);
            tx_vypis.Text = vys.ToString();
            vysc = 0;
        }

        private void mocnit3(object sender, RoutedEventArgs e)
        {
            op = 6;
            c = Convert.ToDouble(tx_vypis.Text);
            vys = Math.Pow(c, 3);
            tx_vypis.Text = vys.ToString();
            vysc = 0;
        }
        
        private void mocnitx(object sender, RoutedEventArgs e)
        {
            op = 7;
            if (vysc == 0 && moc == 0)
            {
                x = Convert.ToDouble(tx_vypis.Text);
                tx_vypis.Text = "";
            }
            else
            {
                c = Convert.ToDouble(tx_vypis.Text);
                vys = Math.Pow(x, c);
                tx_vypis.Text = vys.ToString();
            }
            
            moc++;
            vysc = 0;
        }

        private void vysledek(object sender, RoutedEventArgs e)
        {

            c = Convert.ToDouble(tx_vypis.Text);

            if(op == 0)
            {
                vys = c;
            }
            else if(op == 1)
            {
                vys += c;
            }
            else if(op == 2)
            {
                vys -= c;
            }
            else if (op == 3)
            {
                vys *= c;
            }
            else if (op == 4)
            {
                if(c == 0)
                {
                    p = 1;
                }
                else
                {
                    vys /= c;
                }
            }
            /*else if (op == 7)
            {
                
                if(vysc != 0 || moc != 0)
                {
                    for (; c-1 > 0; c--)
                    {
                        vys *= x;
                    }
                }
                else
                {
                    for (; c > 0; c--)
                    {
                        vys *= x;
                    }
                }
                
            }*/

            if(p == 0)
            {
                tx_vypis.Text = vys.ToString();
                vysc++;
            }
            else if (p == 1)
            {
                tx_vypis.Text = "e";
            }
        }

        private void Goto_Prevody(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(Prevody));
        }
    }
}
