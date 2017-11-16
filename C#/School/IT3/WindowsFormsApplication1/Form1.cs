using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Form1_SizeChanged(this, null);
        }

        private void Bt_ToggleHelloWorld_Click(object sender, EventArgs e)
        {
            La_HelloWorld.Visible = !La_HelloWorld.Visible;
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            La_HelloWorld.Center(this, new Point(0, -La_HelloWorld.Height));
            Bt_ToggleHelloWorld.Center(this, new Point(0, Bt_ToggleHelloWorld.Height));
        }
    }

    public static class ControlExtensions
    {
        public static void Center(this Control control, Control parent, Point offset)
        {
            control.Location = new Point(((parent.Width - control.Width) / 2) + offset.X, ((parent.Height - control.Height) / 2) + offset.Y);
        }
    }
}
