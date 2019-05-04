using System.Windows.Controls;

namespace TAG
{
    public sealed partial class Generator : Page
    {
        public Generator()
        {
            InitializeComponent();
            DataContext = new TextFontDefinition();
        }
    }
}
