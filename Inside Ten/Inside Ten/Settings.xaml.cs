namespace InsideTen
{
    public sealed partial class Settings : PageBase
    {
        private App App
        {
            get { return App.Current; }
        }

        public Settings()
        {
            InitializeComponent();
        }
    }
}
