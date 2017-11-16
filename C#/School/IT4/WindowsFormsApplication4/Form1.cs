using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            try
            {
                double tb1 = double.Parse(textBox1.Text);
                double tb2 = double.Parse(textBox2.Text);

                await Task.Run(async () =>
                {
                    for (int i = 0; i <= 100; i++)
                    {
                        await Task.Delay(new Random().Next(0, 100));
                        progressBar1.BeginInvoke(new Action(() =>
                        {
                            progressBar1.Value = i;
                        })).AsyncWaitHandle.WaitOne();
                    }
                });
                
                if (radioButton1.Checked)
                {
                    label1.Text = (tb1 + tb2).ToString();
                    BackColor = Color.DarkTurquoise;
                    Size = new Size(Size.Width, Size.Height + 50);
                }
                else if (radioButton2.Checked)
                {
                    label1.Text = (tb1 - tb2).ToString();
                    BackColor = Color.DodgerBlue;
                    Size = new Size(Size.Width, Size.Height - 50);
                }
                else if (radioButton3.Checked)
                {
                    label1.Text = (tb1 * tb2).ToString();
                    BackColor = Color.Firebrick;
                    Size = new Size(Size.Width + 50, Size.Height);
                }
                else if (radioButton4.Checked)
                {
                    if (tb2 == .0)
                    {
                        throw new Exception("Nenene :)))");
                    }

                    label1.Text = (tb1 / tb2).ToString();
                    BackColor = Color.FromArgb(0x11, 0x3b, 0xb3);
                    Size = new Size(Size.Width - 50, Size.Height);
                }

                Top += 50;
                Left += 50;
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.Message);
            }
        }
    }
}
