using System;
using System.Linq;
using UWPHelper.Utilities;
using Windows.Foundation.Metadata;
using Windows.System;
using Windows.UI.Core;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace FF_Časovač
{
    public sealed partial class MainPage : Page
    {
        private readonly ThreadPoolTimer timer = new ThreadPoolTimer(TimeSpan.FromSeconds(1));
        private readonly TimeSpan[] gongTimeSpans = { TimeSpan.FromHours(1), TimeSpan.FromMinutes(15), TimeSpan.FromMinutes(3), TimeSpan.Zero };

        private TimeSpan time;

        public MainPage()
        {
            timer.Tick += Timer_Tick;
            KeyboardHelper.CoreKeyDown += KeyboardHelper_CoreKeyDown;

            InitializeComponent();
        }

        private void KeyboardHelper_CoreKeyDown(CoreWindow sender, KeyEventArgs args)
        {
            if (args.Handled)
            {
                return;
            }

            switch (args.VirtualKey)
            {
                case VirtualKey.F11:
                    if (ApiInformation.IsTypePresent("Windows.UI.ViewManagement.ApplicationView"))
                    {
                        args.Handled = true;
                        ApplicationView applicationView = ApplicationView.GetForCurrentView();

                        if (applicationView.IsFullScreenMode)
                        {
                            applicationView.ExitFullScreenMode();
                        }
                        else
                        {
                            applicationView.TryEnterFullScreenMode();
                        }
                    }
                    

                    break;
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            time -= TimeSpan.FromSeconds(1);

            if (gongTimeSpans.Any(t => time == t))
            {
                // Play gong
            }
            else if (time >= TimeSpan.FromSeconds(3))
            {
                // Play peep
            }

            if (time == gongTimeSpans[gongTimeSpans.Length - 2])
            {
                Sb_Blinking.Begin();
            }
            else if (time == TimeSpan.Zero)
            {
                timer.Stop();
            }

            TB_Hours.Text   = time.Hours.ToString("D2");
            TB_Minutes.Text = time.Minutes.ToString("D2");
            TB_Seconds.Text = time.Seconds.ToString("D2");
        }

        private void Start(object sender, RoutedEventArgs e)
        {
            time = TP_Input.Time;

            Gr_Initialization.Visibility = Visibility.Collapsed;
            timer.Start();
        }
    }
}
