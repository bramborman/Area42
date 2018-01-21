using System;
using System.Drawing;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication8
{
    public partial class Form1 : Form
    {
        private const int SLEEP = 1000;

        private readonly Graphics graphics;

        public Form1()
        {
            InitializeComponent();
            graphics = pictureBox1.CreateGraphics();
        }

        private void DrawHouse(object sender, EventArgs e)
        {
            Task.Run(async () =>
            {
                Pen pen = new Pen(Color.Black, 5f);

                graphics.DrawLine(pen, 1, 200, 100, 200);
                await Task.Delay(SLEEP);
                graphics.DrawLine(pen, 100, 200, 100, 100);
                await Task.Delay(SLEEP);
                graphics.DrawLine(pen, 100, 100, 50, 1);
                await Task.Delay(SLEEP);
                graphics.DrawLine(pen, 50, 1, 1, 100);
                await Task.Delay(SLEEP);
                graphics.DrawLine(pen, 1, 100, 1, 200);
                await Task.Delay(SLEEP);
                graphics.DrawLine(pen, 1, 200, 100, 100);
                await Task.Delay(SLEEP);
                graphics.DrawLine(pen, 1, 100, 100, 100);
                await Task.Delay(SLEEP);
                graphics.DrawLine(pen, 1, 100, 100, 200);
            });
        }

        private void Draw(object sender, EventArgs e)
        {
            Task.Run(async () =>
            {
                const int DIFFERENCE = 5;
                int windowSize = Math.Min(pictureBox1.Width, pictureBox1.Height);

                for (int i = 0; i < windowSize / DIFFERENCE / 2; i++)
                {
                    Brush brush = i % 2 == 0 ? Brushes.Black : Brushes.White;
                    int diff = i * DIFFERENCE;
                    int size = windowSize - (2 * diff);
                    graphics.FillEllipse(brush, diff, diff, size, size);

                    await Task.Delay(SLEEP);
                }
            });
        }

        private void Clear(object sender, EventArgs e)
        {
            graphics.Clear(pictureBox1.BackColor);
        }
    }
}
