using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication7
{
    public partial class Form1 : Form
    {
        private readonly Timer t = new Timer();

        private int diff = 1;

        public Form1()
        {
            InitializeComponent();
            t.Tick += T_Tick;
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
        }
    }
}
