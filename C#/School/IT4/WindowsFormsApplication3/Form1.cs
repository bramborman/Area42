using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApplication3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void ChangeBackgroundColor(object sender, EventArgs e)
        {
            string color = ((RadioButton)sender).Name.Remove(0, 3);
            BackColor = Color.FromName(color);
        }
    }
}
