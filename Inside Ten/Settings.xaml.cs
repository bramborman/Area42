using UWPHelper.Utilities;

namespace InsideTen
{
    public sealed partial class Settings : PageBase
    {
        private AccentColorHelper AccentColorHelper
        {
            get { return AccentColorHelper.Current; }
        }

        public Settings()
        {
            InitializeComponent();
        }
    }
}
