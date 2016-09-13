using System.Threading.Tasks;
using UWPHelper.Utilities;
using Windows.Storage;
using Windows.System.Profile;

namespace InsideTen
{
    public class AppData : NotifyPropertyChangedBase
    {
        const string FILE = "AppData.json";

        public static AppData Current { get; private set; }
        public static bool ShowLoadingError { get; set; }

        public bool ShowAbout
        {
            get { return GetValue<bool>(nameof(ShowAbout)); }
            set { SetValue(nameof(ShowAbout), ref value); }
        }
        public bool ShowMobile
        {
            get { return GetValue<bool>(nameof(ShowMobile)); }
            set { SetValue(nameof(ShowMobile), ref value); }
        }

        public AppData()
        {
            RegisterProperty(nameof(ShowAbout), typeof(bool), true);
            RegisterProperty(nameof(ShowMobile), typeof(bool), AnalyticsInfo.VersionInfo.DeviceFamily == "Windows.Mobile");
        }

        public Task SaveAsync()
        {
            return StorageFileHelper.SaveObjectAsync(this, FILE, ApplicationData.Current.LocalFolder);
        }

        public static async Task LoadAsync()
        {
            var loadObjectAsyncResult = await StorageFileHelper.LoadObjectAsync<AppData>(FILE, ApplicationData.Current.LocalFolder);
            Current             = loadObjectAsyncResult.Object;
            ShowLoadingError    = !loadObjectAsyncResult.Success;

            Current.PropertyChanged += async (sender, e) =>
            {
                await Current.SaveAsync();
            };
        }
    }
}