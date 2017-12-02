using System.Drawing;
using System.Windows.Forms;

namespace Videostop
{
    public sealed partial class DialogForm : Form
    {
        public DialogForm(string title, string text)
        {
            InitializeComponent();

            TitleLabel.Text = title;
            TextLabel.Text = text;
        }

        protected override void OnPaintBackground(PaintEventArgs e)
        {
            base.OnPaintBackground(e);
            e.Graphics.DrawRectangle(new Pen(Color.Black, 3f), 1.5f, 1.5f, Width - 3f, Height - 3f);
        }
    }
}
