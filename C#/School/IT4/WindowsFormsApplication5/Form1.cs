using System;
using System.Windows.Forms;

namespace WindowsFormsApplication5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label1.Left += label1.Size.Width;

            if (label1.Left + label1.Width >= Width)
            {
                label1.Left = 0;
            }
        }
    }
}
