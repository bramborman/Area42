using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApplication7
{
    public partial class Form1 : Form
    {
        private readonly Timer t = new Timer();

        private int diff = 1;
        private int attempts = 3;

        public Form1()
        {
            InitializeComponent();
            t.Tick += T_Tick;
            Form1_SizeChanged(null, null);
        }

        private void T_Tick(object sender, EventArgs e)
        {
            progressBar1.Value += diff;
            progressBar2.Value += diff;

            if (progressBar1.Value == 0 || progressBar1.Value == 100)
            {
                diff *= -1;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool _17 = textBox1.Text == "17";
            t.Enabled = _17;
            textBox1.Enabled = !_17;
            button1.Enabled = !_17;

            if (--attempts == 0)
            {
                textBox1.Enabled = false;
                button1.Enabled = false;
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            textBox1.Location = new Point((Width - textBox1.Width) / 2, ((Height - textBox1.Height) / 2) - textBox1.Height - 10);
            button1.Location = new Point((Width - button1.Width) / 2, (Height - button1.Height) / 2);

            progressBar1.Width = Width / 2;
            progressBar2.Width = Width / 2;
            progressBar1.Height = Height;
            progressBar2.Height = Height;

            progressBar1.Location = new Point(0, 0);
            progressBar2.Location = new Point(Width - progressBar2.Width, 0);
        }
    }
}
