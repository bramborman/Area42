using System;
using System.Linq;
using UWPHelper.Utilities;
using Windows.ApplicationModel;
using Windows.Storage;
using Windows.System;
using Windows.UI.Core;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media.Animation;

namespace FF_Časovač
{
    public sealed partial class MainPage : Page
    {
        private readonly ThreadPoolTimer timer      = new ThreadPoolTimer(TimeSpan.FromSeconds(1));
        private readonly TimeSpan[] gongTimeSpans   = { TimeSpan.FromHours(1), TimeSpan.FromMinutes(15), TimeSpan.FromMinutes(3), TimeSpan.Zero };
        private readonly MediaElement gongSound     = new MediaElement { Volume = 1.0 };
        private readonly MediaElement beepSound     = new MediaElement { Volume = 0.2 };

        private TimeSpan time;

        public MainPage()
        {
            InitializeSoundAsset(gongSound, "Gong.mp3");
            InitializeSoundAsset(beepSound, "Beep.mp3");

            timer.Tick += Timer_Tick;
            KeyboardHelper.CoreKeyDown += KeyboardHelper_CoreKeyDown;

            InitializeComponent();
        }

        private async void InitializeSoundAsset(MediaElement mediaElement, string fileName)
        {
            mediaElement.AutoPlay = false;

            StorageFolder folder = await Package.Current.InstalledLocation.GetFolderAsync("Assets");
            StorageFile file     = await folder.GetFileAsync(fileName);
            mediaElement.SetSource(await file.OpenAsync(FileAccessMode.Read), "");
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

                    break;
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            time -= TimeSpan.FromSeconds(1);

            if (gongTimeSpans.Any(t => time == t))
            {
                gongSound.Play();
            }
            else if (time <= TimeSpan.FromSeconds(3))
            {
                beepSound.Play();
            }

            if (time <= gongTimeSpans[gongTimeSpans.Length - 2] && Sb_Blinking.GetCurrentState() == ClockState.Stopped)
            {
                Sb_Blinking.Begin();
            }

            if (time == TimeSpan.Zero)
            {
                timer.Stop();
            }
            else if (time < TimeSpan.Zero)
            {
                timer.Stop();
                return;
            }

            TB_Hours.Text   = time.Hours.ToString("D2");
            TB_Minutes.Text = time.Minutes.ToString("D2");
            TB_Seconds.Text = time.Seconds.ToString("D2");
        }

        private void Start(object sender, RoutedEventArgs e)
        {
            time = TP_Input.Time;
            ApplicationView.GetForCurrentView().TryEnterFullScreenMode();

            Bo_Initialization.Visibility = Visibility.Collapsed;
            timer.Start();
        }
    }
}
