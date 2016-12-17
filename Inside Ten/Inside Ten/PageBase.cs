using Windows.ApplicationModel.Resources;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace InsideTen
{
    public abstract class PageBase : Page
    {
        public PageBase()
        {
            NavigationCacheMode = NavigationCacheMode.Required;
            Name = ResourceLoader.GetForCurrentView().GetString($"{GetType().Name}Page/Name").ToUpper();
        }
    }
}
