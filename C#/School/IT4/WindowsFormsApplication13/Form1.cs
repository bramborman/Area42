using System;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsApplication13
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void passwordInput_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
            {
                Application.Exit();
                return;
            }

            if (e.KeyCode != Keys.Enter || passwordInput.Text.Length < 5)
            {
                return;
            }

            string imageName = null;
            string password = passwordInput.Text;

            if (string.Equals(password, "swamp", StringComparison.InvariantCultureIgnoreCase))
            {
                imageName = "swamp.png";
            }
            else if (password.Length <= 6)
            {
                imageName = "worstest.jpg";
            }
            else if (password.Length <= 8)
            {
                imageName = "worst.png";
            }
            else if (password.Length <= 10)
            {
                imageName = "bad.jpg";
            }
            else if (password.Length <= 12)
            {
                imageName = "ok.png";
            }
            else if (CheckPasswordComplexity(password))
            {
                imageName = "bestest.jpg";
            }
            else
            {
                imageName = "best.jpg";
            }

            Image image = Image.FromFile("Images/" + imageName);

            Form form = new Form()
            {
                BackColor = Color.White,
                BackgroundImage = image,
                ShowIcon = false,
                FormBorderStyle = FormBorderStyle.None,
                StartPosition = FormStartPosition.CenterParent,
                Width = image.Width,
                Height = image.Height
            };
            form.Click += (sender2, e2) =>
            {
                form.Hide();
            };
            form.KeyDown += (sender2, e2) =>
            {
                if (e2.KeyCode == Keys.Enter || e2.KeyCode == Keys.Escape)
                {
                    form.Hide();
                }
            };

            passwordInput.Text = null;
            form.ShowDialog(this);
        }

        private bool CheckPasswordComplexity(string password)
        {
            bool lowerLetter = false;
            bool upperLetter = false;
            bool digit = false;
            bool specialChar = false;

            foreach (char ch in password)
            {
                if (char.IsLetter(ch))
                {
                    if (char.IsLower(ch))
                    {
                        lowerLetter = true;
                    }
                    else if (char.IsUpper(ch))
                    {
                        upperLetter = true;
                    }
                }
                else if (char.IsDigit(ch))
                {
                    digit = true;
                }
                else
                {
                    specialChar = true;
                }
            }

            return lowerLetter && upperLetter && digit && specialChar;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
            {
                Application.Exit();
            }
        }
    }
}
