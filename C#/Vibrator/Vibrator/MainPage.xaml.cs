using System;
using System.Threading;
using System.Threading.Tasks;
using Windows.Phone.Devices.Notification;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace Vibrator
{
    public sealed partial class MainPage : Page
    {
        private static readonly VibrationDevice vibrationDevice = VibrationDevice.GetDefault();
        private static readonly ManualResetEvent resetEvent = new ManualResetEvent(false);
        private static readonly Task vibrationTask = new Task(async () =>
        {
            while (true)
            {
                resetEvent.WaitOne();
                vibrationDevice.Vibrate(TimeSpan.FromMilliseconds(200));
                await Task.Delay(TimeSpan.FromMilliseconds(150));
            }
        });

        private bool isVibrating = false;

        public MainPage()
        {
            InitializeComponent();
            vibrationTask.Start();
        }

        private void ToggleVibrations(object sender, RoutedEventArgs e)
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
        }
    }
}
