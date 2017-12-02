using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Videostop
{
    public sealed partial class MainForm : Form
    {
        private const int DELAY                 = 200;
        private const int POINTS_DEFAULT        =  0;
        private const int POINTS_MAX            =  3;
        private const int POINTS_MIN            = -3;
        private const int POINTS_ADDITION_2     =  1;
        private const int POINTS_ADDITION_3     =  2;
        private const int POINTS_SUBTRACTION    =  1;
        private const int DICE_DEFAULT_VALUE    =  1;

        private static readonly Pen diceOutlinePen = new Pen(Color.Black, 3f);
        private static readonly Brush diceBrush = Brushes.White;
        private static readonly Brush dotBrush = new SolidBrush(Color.FromArgb(0x11, 0x6b, 0xb3));
        private static readonly Random random = new Random();

        private readonly int[] values = new int[3];
        private readonly ManualResetEvent resetEvent = new ManualResetEvent(false);
        private readonly Graphics graphics;
        private readonly int diceSize;
        private readonly int diceMargin;
        private readonly string pointsLabelPlaceholder;

        private bool isDragging;
        private Point startPoint;
        private int points;
        
        public MainForm()
        {
            InitializeComponent();
            pointsLabelPlaceholder = PointsLabel.Text;

            graphics = PictureBox.CreateGraphics();
            graphics.SmoothingMode = SmoothingMode.AntiAlias;
            diceSize = PictureBox.Width / 5;
            diceMargin = diceSize / 2;

            Task.Run(async () =>
            {
                await Task.Delay(100);
                ResetVariables();
            });
            Task.Run((Action)Worker);
        }

        private void StartStopButton_Click(object sender, EventArgs e)
        {
            if (resetEvent.WaitOne(0))
            {
                resetEvent.Reset();
                StartStopButton.Text = "START";

                int count = values.Distinct().Count();

                switch (count)
                {
                    case 1:
                        // There is 1 value
                        // -- 3 dice have the same values
                        points += POINTS_ADDITION_3;
                        break;

                    case 2:
                        // There are 2 different values
                        // -- 2 dice have the same values
                        points += POINTS_ADDITION_2;
                        break;

                    case 3:
                        // There are 3 different values
                        // -- no dice have the same values
                        points -= POINTS_SUBTRACTION;
                        break;
                }
            }
            else
            {
                resetEvent.Set();
                StartStopButton.Text = "STOP";
            }

            UpdatePointsLabel();

            if (points == POINTS_MAX)
            {
                new DialogForm("(⌐■_■)", "You won!").ShowDialog(this);
                ResetVariables();
            }
            else if (points == POINTS_MIN)
            {
                new DialogForm("⤜(ʘ_ʘ)⤏", "You lost!").ShowDialog(this);
                ResetVariables();
            }
        }

        private void ResetVariables()
        {
            points = POINTS_DEFAULT;
            PointsLabel.Text = pointsLabelPlaceholder;

            for (int i = 0; i < values.Length; i++)
            {
                values[i] = DICE_DEFAULT_VALUE;
            }

            DrawDice(diceMargin, diceSize);
        }

        private async void Worker()
        {
            while (resetEvent.WaitOne())
            {
                for (int i = 0; i < values.Length; i++)
                {
                    values[i] = random.Next(1, 7);
                }

                DrawDice(diceMargin, diceSize);
                await Task.Delay(DELAY);
            }
        }

        private void DrawDice(int margin, int size)
        {
            int y = (PictureBox.Height - size) / 2;

            for (int i = 0; i < values.Length; i++)
            {
                DrawDice(margin + (i * (margin + size)), y, size, values[i]);
            }
        }

        private void DrawDice(int x, int y, int size, int number)
        {
            if (number < 1 || number > 6)
            {
                return;
            }
            
            graphics.FillRectangle(diceBrush, x, y, size, size);
            graphics.DrawRectangle(diceOutlinePen, x, y, size, size);

            int dotSize = size / 5;
            int left    = x + dotSize;
            int center  = x + (2 * dotSize);
            int right   = x + (3 * dotSize);
            int top     = y + dotSize;
            int middle  = y + (2 * dotSize);
            int bottom  = y + (3 * dotSize);

            if (number >= 2)
            {
                // Top left
                graphics.FillEllipse(dotBrush, left, top, dotSize, dotSize);
                // Bottom right
                graphics.FillEllipse(dotBrush, right, bottom, dotSize, dotSize);
            }

            if (number >= 4)
            {
                // Top right
                graphics.FillEllipse(dotBrush, right, top, dotSize, dotSize);
                // Bottom left
                graphics.FillEllipse(dotBrush, left, bottom, dotSize, dotSize);
            }

            if (number == 6)
            {
                // Middle left
                graphics.FillEllipse(dotBrush, left, middle, dotSize, dotSize);
                // Middle right
                graphics.FillEllipse(dotBrush, right, middle, dotSize, dotSize);
            }

            if (number % 2 == 1)
            {
                // Center
                graphics.FillEllipse(dotBrush, center, middle, dotSize, dotSize);
            }
        }

        private void UpdatePointsLabel()
        {
            PointsLabel.Text = "Points: " + points;
        }

        private void MinimizeButton_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Minimized;
        }

        private void CloseButton_Click(object sender, EventArgs e)
        {
            Close();
        }
        
        private void TitleLabel_MouseUp(object sender, MouseEventArgs e)
        {
            isDragging = false;
        }

        private void TitleLabel_MouseDown(object sender, MouseEventArgs e)
        {
            startPoint = e.Location;
            isDragging = true;
        }

        private void TitleLabel_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDragging)
            {
                Point point = PointToScreen(new Point(e.X, e.Y));
                Location = new Point(point.X - startPoint.X,
                                     point.Y - startPoint.Y);
            }
        }

        protected override void OnActivated(EventArgs e)
        {
            base.OnActivated(e);
            Task.Run(async () =>
            {
                await Task.Delay(10);
                DrawDice(diceMargin, diceSize);
            });
        }
    }
}