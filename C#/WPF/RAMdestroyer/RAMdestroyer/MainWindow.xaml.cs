using System;
using System.Collections.Generic;
using System.Windows;

namespace RAMdestroyer
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void StartDestroyer(object sender, RoutedEventArgs e)
        {
            List<SpaceWaster> destroyer = new List<SpaceWaster>();
            GC.KeepAlive(destroyer);

            for(int i = 0; i < 1000000000; i++)
            {
                SpaceWaster sw = new SpaceWaster();
                GC.KeepAlive(sw);
                destroyer.Add(sw);
            }
        }
    }

    class SpaceWaster
    {
        int r = 0;
        Random rand = new Random();

        List<decimal> destroyer1 = new List<decimal>();
        List<decimal> destroyer2 = new List<decimal>();
        List<decimal> destroyer3 = new List<decimal>();
        List<decimal> destroyer4 = new List<decimal>();
        List<decimal> destroyer5 = new List<decimal>();
        List<decimal> destroyer6 = new List<decimal>();
        List<decimal> destroyer7 = new List<decimal>();
        List<decimal> destroyer8 = new List<decimal>();
        List<decimal> destroyer9 = new List<decimal>();
        List<decimal> destroyer10 = new List<decimal>();
        List<decimal> destroyer11 = new List<decimal>();
        List<decimal> destroyer12 = new List<decimal>();
        List<decimal> destroyer13 = new List<decimal>();
        List<decimal> destroyer14 = new List<decimal>();
        List<decimal> destroyer15 = new List<decimal>();
        List<decimal> destroyer16 = new List<decimal>();
        List<decimal> destroyer17 = new List<decimal>();
        List<decimal> destroyer18 = new List<decimal>();
        List<decimal> destroyer19 = new List<decimal>();
        List<decimal> destroyer20 = new List<decimal>();
        List<decimal> destroyer21 = new List<decimal>();
        List<decimal> destroyer22 = new List<decimal>();
        List<decimal> destroyer23 = new List<decimal>();
        List<decimal> destroyer24 = new List<decimal>();
        List<decimal> destroyer25 = new List<decimal>();
        List<decimal> destroyer26 = new List<decimal>();
        List<decimal> destroyer27 = new List<decimal>();
        List<decimal> destroyer28 = new List<decimal>();
        List<decimal> destroyer29 = new List<decimal>();
        List<decimal> destroyer30 = new List<decimal>();
        List<decimal> destroyer31 = new List<decimal>();
        List<decimal> destroyer32 = new List<decimal>();
        List<decimal> destroyer33 = new List<decimal>();
        List<decimal> destroyer34 = new List<decimal>();
        List<decimal> destroyer35 = new List<decimal>();
        List<decimal> destroyer36 = new List<decimal>();
        List<decimal> destroyer37 = new List<decimal>();
        List<decimal> destroyer38 = new List<decimal>();
        List<decimal> destroyer39 = new List<decimal>();
        List<decimal> destroyer40 = new List<decimal>();

        public SpaceWaster()
        {
            GC.KeepAlive(r);
            GC.KeepAlive(rand);

            GC.KeepAlive(destroyer1);
            GC.KeepAlive(destroyer2);
            GC.KeepAlive(destroyer3);
            GC.KeepAlive(destroyer4);
            GC.KeepAlive(destroyer5);
            GC.KeepAlive(destroyer6);
            GC.KeepAlive(destroyer7);
            GC.KeepAlive(destroyer8);
            GC.KeepAlive(destroyer9);
            GC.KeepAlive(destroyer10);
            GC.KeepAlive(destroyer11);
            GC.KeepAlive(destroyer12);
            GC.KeepAlive(destroyer13);
            GC.KeepAlive(destroyer14);
            GC.KeepAlive(destroyer15);
            GC.KeepAlive(destroyer16);
            GC.KeepAlive(destroyer17);
            GC.KeepAlive(destroyer18);
            GC.KeepAlive(destroyer19);
            GC.KeepAlive(destroyer20);
            GC.KeepAlive(destroyer21);
            GC.KeepAlive(destroyer22);
            GC.KeepAlive(destroyer23);
            GC.KeepAlive(destroyer24);
            GC.KeepAlive(destroyer25);
            GC.KeepAlive(destroyer26);
            GC.KeepAlive(destroyer27);
            GC.KeepAlive(destroyer28);
            GC.KeepAlive(destroyer29);
            GC.KeepAlive(destroyer30);
            GC.KeepAlive(destroyer31);
            GC.KeepAlive(destroyer32);
            GC.KeepAlive(destroyer33);
            GC.KeepAlive(destroyer34);
            GC.KeepAlive(destroyer35);
            GC.KeepAlive(destroyer36);
            GC.KeepAlive(destroyer37);
            GC.KeepAlive(destroyer38);
            GC.KeepAlive(destroyer39);
            GC.KeepAlive(destroyer40);

            for (int i = 0; i < 1000000000; i++)
            {
                r = rand.Next();
                GC.KeepAlive(r);

                destroyer1.Add(r);
                destroyer2.Add(r);
                destroyer3.Add(r);
                destroyer4.Add(r);
                destroyer5.Add(r);
                destroyer6.Add(r);
                destroyer7.Add(r);
                destroyer8.Add(r);
                destroyer9.Add(r);
                destroyer10.Add(r);
                destroyer11.Add(r);
                destroyer12.Add(r);
                destroyer13.Add(r);
                destroyer14.Add(r);
                destroyer15.Add(r);
                destroyer16.Add(r);
                destroyer17.Add(r);
                destroyer18.Add(r);
                destroyer19.Add(r);
                destroyer20.Add(r);
                destroyer21.Add(r);
                destroyer22.Add(r);
                destroyer23.Add(r);
                destroyer24.Add(r);
                destroyer25.Add(r);
                destroyer26.Add(r);
                destroyer27.Add(r);
                destroyer28.Add(r);
                destroyer29.Add(r);
                destroyer30.Add(r);
                destroyer31.Add(r);
                destroyer32.Add(r);
                destroyer33.Add(r);
                destroyer34.Add(r);
                destroyer35.Add(r);
                destroyer36.Add(r);
                destroyer37.Add(r);
                destroyer38.Add(r);
                destroyer39.Add(r);
                destroyer40.Add(r);
            }
        }
    }
}
