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

namespace Skola_WPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        List<Zak> seznamZaku = new List<Zak>();

        public MainWindow()
        {
            InitializeComponent();

            dg_seznamZaku.ItemsSource = seznamZaku;
        }

        private void PridatZaka(object sender, RoutedEventArgs e)
        {
            int intTemp;
            double doubleTemp;

            Zak zak = new Zak();

            zak.Jmeno = tx_jmeno.Text;
            zak.Prijmeni = tx_prijmeni.Text;
            zak.JeMuz = Convert.ToBoolean(cb_muz.IsChecked);

            try
            {
                zak.DatumNarozeni = Convert.ToDateTime(dt_narozeni.Text);
            }
            catch { }

            zak.Obor = tx_obor.Text;

            double.TryParse(tx_prumer.Text, out doubleTemp);
            zak.Prumer = doubleTemp;

            int.TryParse(tx_absence.Text, out intTemp);
            zak.Absence = intTemp;

            zak.ID = Guid.NewGuid();

            seznamZaku.Add(zak);

            dg_seznamZaku.Items.Refresh();
        }

        private void OdebratZaka(object sender, RoutedEventArgs e)
        {
            /*Zak vybrano = dg_seznamZaku.SelectedItem;

            seznamZaku.Remove((Zak)vybrano);*/

            Zak vybrano = (Zak)dg_seznamZaku.SelectedItem;

            seznamZaku.Remove(vybrano);
            dg_seznamZaku.Items.Refresh();
        }

        /*private void ZobrazitZaky(object sender, RoutedEventArgs e)
        {
            dg_seznamZaku.ItemsSource = seznamZaku;
            dg_seznamZaku.Items.Refresh();
        }*/

        private void NastaveniTridy(object sender, RoutedEventArgs e)
        {
            NastaveniTridy nastaveni = new NastaveniTridy();
            nastaveni.Show();
        }
    }
}
