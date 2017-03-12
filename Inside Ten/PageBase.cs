using UWPHelper.UI;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace InsideTen
{
    public abstract class PageBase : Page
    {
        protected AccentColorHelper AccentColorHelper
        {
            get { return AccentColorHelper.GetForCurrentView(); }
        }

        public PageBase()
        {
            NavigationCacheMode = NavigationCacheMode.Required;
        }
    }
}
