using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApplication11
{
    public partial class MainForm : Form
    {
        System.Threading.Timer timer;

        public MainForm()
        {
            InitializeComponent();
            ColorChanged(null, null);
            timer = new System.Threading.Timer(TimerCallback, null, 0, 150);
        }

        private void ColorChanged(object sender, EventArgs e)
        {
            BackColor = Color.FromArgb((int)redInput.Value, (int)greenInput.Value, (int)blueInput.Value);
            Text = $"Colors: {BackColor.R:X2}{BackColor.G:X2}{BackColor.B:X2}";
        }

        private void TimerCallback(object state)
        {
            if (!IsDisposed)
            {
                try
                {
                    Invoke(new Action(() =>
                    {
                        timeLabel.Text = DateTime.Now.ToString("HH:mm:ss");
                    }));
                }
                catch
                {

                }
            }
            else
            {
                timer?.Dispose();
                timer = null;
            }
        }
    }
}
