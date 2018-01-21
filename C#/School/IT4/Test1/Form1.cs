using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test1
{
    public partial class Form1 : Form
    {
        private int value;
        private int drawnValue;
        private Graphics g;

        public Form1()
        {
            InitializeComponent();
            g = pictureBox1.CreateGraphics();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            drawnValue = 0;
            g.Clear(pictureBox1.BackColor);
            label1.Visible = false;

            if (!int.TryParse(textBox1.Text, out value) || value < 0 || value > 200)
            {
                MessageBox.Show("Zadej 0-200", "P O Z O R");
                return;
            }

            drawnValue = 0;
            g.Clear(pictureBox1.BackColor);
            g.DrawRectangle(new Pen(Color.Black, 2f), 10, 10, 400, 10);

            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            g.FillRectangle(Brushes.Blue, 10, 10, drawnValue * 2, 10);

            if (drawnValue++ == value)
            {
                timer1.Stop();
                label1.Text = (value / 2) + "%";
                label1.Visible = true;
            }
        }
    }
}
