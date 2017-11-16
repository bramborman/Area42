using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApplication6
{
    public partial class Form1 : Form
    {
        private static readonly Color BackHighlight = Color.Black;
        private static readonly Color ForeHighlight = Color.White;
        private static readonly Color BackNormal = Color.Transparent;
        private static readonly Color ForeNormal = Color.Black;

        private readonly List<Label> labels;

        public Form1()
        {
            InitializeComponent();

            labels = new List<Label>()
            {
                La_TezkaPodvyziva,
                La_Podvaha,
                La_IdealniVaha,
                La_Nadvaha,
                La_Obezita1,
                La_Obezita2,
                La_Obezita3
            };

            PB_Height.DataBindings.Add(nameof(PB_Height.Minimum), NUD_Height, nameof(NUD_Height.Minimum));
            PB_Height.DataBindings.Add(nameof(PB_Height.Maximum), NUD_Height, nameof(NUD_Height.Maximum));
            PB_Height.DataBindings.Add(nameof(PB_Height.Value), NUD_Height, nameof(NUD_Height.Value));

            PB_Weight.DataBindings.Add(nameof(PB_Weight.Minimum), NUD_Weight, nameof(NUD_Weight.Minimum));
            PB_Weight.DataBindings.Add(nameof(PB_Weight.Maximum), NUD_Weight, nameof(NUD_Weight.Maximum));
            PB_Weight.DataBindings.Add(nameof(PB_Weight.Value), NUD_Weight, nameof(NUD_Weight.Value));

            NUD_ValueChanged(null, null);
            Form1_SizeChanged(null, null);

            while (MessageBox.Show("Nazdar", "Čau", MessageBoxButtons.RetryCancel, MessageBoxIcon.Error, MessageBoxDefaultButton.Button1, MessageBoxOptions.RightAlign) == DialogResult.Retry) ;
        }

        private void NUD_ValueChanged(object sender, EventArgs e)
        {
            float weight = Convert.ToSingle(NUD_Weight.Value);
            float height = Convert.ToSingle(NUD_Height.Value) / 100f;
            float result = weight / (height * height);

            La_Result.Text = "BMI: " + result;

            foreach (Label label in labels)
            {
                label.ForeColor = ForeNormal;
                label.BackColor = BackNormal;
            }

            if (result <= 16.5f)
            {
                La_TezkaPodvyziva.ForeColor = ForeHighlight;
                La_TezkaPodvyziva.BackColor = BackHighlight;
            }
            else if (result <= 18.5f)
            {
                La_Podvaha.ForeColor = ForeHighlight;
                La_Podvaha.BackColor = BackHighlight;
            }
            else if (result <= 25f)
            {
                La_IdealniVaha.ForeColor = ForeHighlight;
                La_IdealniVaha.BackColor = BackHighlight;
            }
            else if (result <= 30f)
            {
                La_Nadvaha.ForeColor = ForeHighlight;
                La_Nadvaha.BackColor = BackHighlight;
            }
            else if (result <= 35f)
            {
                La_Obezita1.ForeColor = ForeHighlight;
                La_Obezita1.BackColor = BackHighlight;
            }
            else if (result <= 40f)
            {
                La_Obezita2.ForeColor = ForeHighlight;
                La_Obezita2.BackColor = BackHighlight;
            }
            else
            {
                La_Obezita3.ForeColor = ForeHighlight;
                La_Obezita3.BackColor = BackHighlight;
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            Pa_Content.Location = new Point((Width - Pa_Content.Width) / 2, (Height - Pa_Content.Height) / 2);
        }
    }
}
