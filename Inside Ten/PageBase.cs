using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace InsideTen
{
    public abstract class PageBase : Page
    {
        public PageBase()
        {
            NavigationCacheMode = NavigationCacheMode.Required;
        }
    }
}
