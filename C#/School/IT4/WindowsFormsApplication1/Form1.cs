using System;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textFoo_TextChanged(object sender, EventArgs e)
        {
            double wat;
            labelBar.Text = double.TryParse(textFoo.Text, out wat) ? wat.ToString("0.00") : "...";
        }
    }
}
