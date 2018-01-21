using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApplication12
{
    public partial class CardControl : UserControl
    {
        private string _imageName;

        public bool TurningDisabled { get; set; }
        public bool ImageVisible
        {
            get { return !foregroundLabel.Visible; }
            set { foregroundLabel.Visible = !value; }
        }
        public string ImageName
        {
            get { return _imageName; }
            set
            {
                if (_imageName != value)
                {
                    _imageName = value;

                    if (!DesignMode)
                    {
                        BackgroundImage = Image.FromFile("Images/" + ImageName);
                    }
                }
            }
        }

        public CardControl()
        {
            InitializeComponent();
        }

        private void OnClick(object sender, EventArgs e)
        {
            if (!TurningDisabled)
            {
                ImageVisible = !ImageVisible;
            }
        }
    }
}
