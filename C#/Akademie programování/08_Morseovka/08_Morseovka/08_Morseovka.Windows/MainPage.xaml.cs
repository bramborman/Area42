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

namespace _08_Morseovka
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

        private void click_preklad(object sender, RoutedEventArgs e)
        {
            string[] pole = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
            string vstup = tx_vstup.Text.ToUpper();
            string preklad; //pomocná proměnná

            for(int i = 0; i < vstup.Length; i++)
            {
                if (vstup[i] == ' ')
                {
                    tb_vysledek.Text += "/";
                }
                else
                {
                    if (vstup[i] >= 'A' && vstup[i] <= 'Z')
                    {
                        preklad = pole[vstup[i] - 'A'];
                        tb_vysledek.Text += string.Format("{0}/", preklad);
                    }
                    else
                    {
                        tb_vysledek.Text = "ERROR";
                    }
                }
            }
        }
    }
}
