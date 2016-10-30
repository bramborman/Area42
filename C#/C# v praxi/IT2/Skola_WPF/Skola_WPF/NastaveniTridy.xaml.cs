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
using System.Windows.Shapes;

namespace Skola_WPF
{
    /// <summary>
    /// Interaction logic for NastaveniTridy.xaml
    /// </summary>
    public partial class NastaveniTridy : Window
    {
        List<Trida> seznamTrid = new List<Trida>();

        public NastaveniTridy()
        {
            InitializeComponent();

            dg_seznamTrid.ItemsSource = seznamTrid;
        }

        private void PridatTridu(object sender, RoutedEventArgs e)
        {
            int temp;

            Trida trida = new Trida();

            trida.Jmeno = tx_jmenoTridy.Text;

            int.TryParse(tx_kapacita.Text, out temp);
            trida.MaxKapacita = temp;

            trida.Umisteni = tx_umisteni.Text;

            Ucitel ucitel = new Ucitel();

            ucitel.Jmeno = tx_jmeno.Text;
            ucitel.Prijmeni = tx_prijmeni.Text;
            ucitel.JeMuz = Convert.ToBoolean(cb_muz.IsChecked);

            try
            {
                ucitel.DatumNarozeni = Convert.ToDateTime(dt_narozeni.Text);
            }
            catch { }

            ucitel.Kabinet = tx_kabinet.Text;
            ucitel.Titul = tx_titul.Text;

            try
            {
                ucitel.Plat = Convert.ToDecimal(tx_plat.Text);
            }
            catch { }

            seznamTrid.Add(trida);
            dg_seznamTrid.Items.Refresh();
        }
    }
}
