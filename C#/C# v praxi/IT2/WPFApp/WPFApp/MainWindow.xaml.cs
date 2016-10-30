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

namespace WPFApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    
    // partial - jedna třída může být ve více souborech
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void bt_showTime_Click(object sender, RoutedEventArgs e)
        {
            lb_time.Content = DateTime.Now.ToString();
        }

        private void nt_Name_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show(string.Format("Length of {0} is {1}", tx_Name.Text, tx_Name.Text.Length), "test", MessageBoxButton.OKCancel, MessageBoxImage.Error);
        }
    }
}
