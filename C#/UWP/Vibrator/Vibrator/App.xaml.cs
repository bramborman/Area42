using System;
using System.Threading;
using System.Threading.Tasks;
using Windows.ApplicationModel.Activation;
using Windows.Phone.Devices.Notification;
using Windows.UI;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media;

namespace Vibrator
{
    public sealed partial class App : Application
    {
        private static readonly VibrationDevice vibrationDevice = VibrationDevice.GetDefault();
        private static readonly ManualResetEvent resetEvent     = new ManualResetEvent(false);
        private static readonly Task vibrationTask              = new Task(async () =>
        {
            while (true)
            {
                resetEvent.WaitOne();
                vibrationDevice.Vibrate(TimeSpan.FromMilliseconds(200));
                await Task.Delay(TimeSpan.FromMilliseconds(150));
            }
        });

        private bool isVibrating = false;

        public App()
        {
            InitializeComponent();
            vibrationTask.Start();
        }
        
        protected override void OnLaunched(LaunchActivatedEventArgs e)
        {
            ApplicationView.PreferredLaunchWindowingMode = ApplicationViewWindowingMode.FullScreen;
            ApplicationView.GetForCurrentView().TryEnterFullScreenMode();

            if (!(Window.Current.Content is Border) && !e.PrelaunchActivated)
            {
                Button button = new Button
                {
                    Style = (Style)Resources["VibrateButton"]
                };

                button.Click += (buttonClickSender, buttonClickE) =>
                {
                    if (isVibrating)
                    {
                        vibrationDevice.Cancel();
                        resetEvent.Reset();
                    }
                    else
                    {
                        resetEvent.Set();
                    }

                    isVibrating = !isVibrating;
                };

                Window.Current.Content = new Border
                {
                    Background  = new SolidColorBrush(Colors.Purple),
                    Child       = button
                };

                Window.Current.Activate();
            }
        }
    }
}
