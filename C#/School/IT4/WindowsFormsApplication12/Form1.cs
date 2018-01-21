using System;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsApplication12
{
    public sealed partial class Form1 : Form
    {
        private const int CARD_COUNT = 12;
        private const int UNIQUE_CARD_COUNT = CARD_COUNT / 2;
        
        public Form1()
        {
            InitializeComponent();

            for (int i = 0; i < CARD_COUNT; i++)
            {
                board.Controls.Add(new CardControl()
                {
                    TurningDisabled = true
                });
            }
        }

        private void playButton_Click(object sender, EventArgs e)
        {
            if (playButton.Text == "PLAY")
            {
                Random random = new Random();

                int[] numbers = Enumerable.Range(1, CARD_COUNT)
                                    .Select(i => i > UNIQUE_CARD_COUNT ? i - UNIQUE_CARD_COUNT : i)
                                    .OrderBy(i => random.Next())
                                    .ToArray();

                for (int i = 0; i < board.Controls.Count; i++)
                {
                    CardControl card = (CardControl)board.Controls[i];
                    card.ImageName = numbers[i].ToString("D3") + ".png";
                    card.TurningDisabled = false;
                    card.ImageVisible = true;
                }

                playButton.Text = "RESET";
            }
            else
            {
                throw new InvalidOperationException(":)");
            }
        }
    }
}
