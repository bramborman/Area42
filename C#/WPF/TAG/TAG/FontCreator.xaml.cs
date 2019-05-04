using System.Collections.ObjectModel;
using System.Windows.Controls;

namespace TAG
{
    public sealed partial class FontCreator : Page
    {
        public const string GENERIC_TEXT = "Generic character";

        public static readonly ObservableCollection<string> chars = new ObservableCollection<string>()
        {
            GENERIC_TEXT, "■", "#", "X", "/", "\\", ".", "_", ",", "~", "'"
        };

        public FontCreator()
        {
            InitializeComponent();
        }
    }
}
