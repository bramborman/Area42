using UWPHelper.Utilities;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace MoreViewsTest
{
    public sealed class AppData : NotifyPropertyChangedBase
    {
        public static AppData Current { get; private set; }

        public ElementTheme Theme
        {
            get { return (ElementTheme)GetValue(nameof(Theme)); }
            set { SetValue(nameof(Theme), ref value); }
        }

        static AppData()
        {
            Current = new AppData();
        }

        private AppData()
        {
            RegisterProperty(nameof(Theme), typeof(ElementTheme), ElementTheme.Default, (oldValue, newValue) =>
            {
                ((Frame)Window.Current.Content).RequestedTheme = (ElementTheme)newValue;
            });
        }
    }
}
