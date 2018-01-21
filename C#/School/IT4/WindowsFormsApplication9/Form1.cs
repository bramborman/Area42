using System;
using System.Drawing;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication9
{
    public partial class Form1 : Form
    {
        private const int POSITION_OFFSET = 15;
        private const int BLOCK_SIZE = 100;
        private const int LIGHT_SIZE = BLOCK_SIZE - POSITION_OFFSET;
        private const int LIGHT_OFFSET = POSITION_OFFSET + ((BLOCK_SIZE - LIGHT_SIZE) / 2);

        private static readonly Brush neutralSemaphoreBrush = Brushes.Gray;
        private static readonly Brush[] semaphoreBrushes = new Brush[]
        {
            Brushes.Red, Brushes.Orange, Brushes.Green
        };
        private static readonly bool[][] semaphoreDefinitions = new bool[][]
        {
            new [] {  true, false, false },
            new [] {  true,  true, false },
            new [] { false, false,  true },
            new [] { false,  true, false }
        };

        private readonly Graphics graphics;

        private bool running;

        public Form1()
        {
            InitializeComponent();
            graphics = pictureBox1.CreateGraphics();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            running = !running;

            if (!running)
            {
                graphics.Clear(pictureBox1.BackColor);
            }
            else
            {
                Task.Run(async () =>
                {
                    int index = 0;

                    while (running)
                    {
                        graphics.FillRectangle(Brushes.Black, POSITION_OFFSET, POSITION_OFFSET, BLOCK_SIZE, 3 * (BLOCK_SIZE + (POSITION_OFFSET / 2)));

                        bool[] definition = semaphoreDefinitions[index];

                        for (int i = 0; i < definition.Length; i++)
                        {
                            Brush brush = definition[i] ? semaphoreBrushes[i] : neutralSemaphoreBrush;
                            graphics.FillEllipse(brush, LIGHT_OFFSET, LIGHT_OFFSET + ((BLOCK_SIZE + (POSITION_OFFSET / 2)) * i), LIGHT_SIZE, LIGHT_SIZE);
                        }
                        
                        if (++index == semaphoreDefinitions.Length)
                        {
                            index = 0;
                        }

                        await Task.Delay(1000);
                    }
                });
            }
        }
    }
}
