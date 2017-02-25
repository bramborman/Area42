using Newtonsoft.Json;
using System;
using System.Threading.Tasks;
using UWPHelper.Utilities;
using Windows.Storage;
using Windows.System.Profile;

namespace InsideTen
{
    public class AppData : NotifyPropertyChangedBase
    {
        private const string FILE_NAME = "AppData.json";

        public static AppData Current { get; private set; }

        [JsonIgnore]
        public bool ShowLoadingError { get; set; }
        public bool ShowAbout
        {
            get { return (bool)GetValue(); }
            set { SetValue(value); }
        }
        public bool ShowMobile
        {
            get { return (bool)GetValue(); }
            set { SetValue(value); }
        }
        public DateTime InsiderInfoLastUpdate
        {
            get { return (DateTime)GetValue(); }
            set { SetValue(value); }
        }

        public AppData()
        {
            RegisterProperty(nameof(ShowAbout), typeof(bool), true);
            RegisterProperty(nameof(ShowMobile), typeof(bool), AnalyticsInfo.VersionInfo.DeviceFamily == "Windows.Mobile");
            RegisterProperty(nameof(InsiderInfoLastUpdate), typeof(DateTime), new DateTime());
        }

        public Task SaveAsync()
        {
            return StorageFileHelper.SaveObjectAsync(this, FILE_NAME, ApplicationData.Current.LocalFolder);
        }

        public static async Task LoadAsync()
        {
#if DEBUG
            if (Current != null)
            {
                throw new Exception("You're not doing it right ;)");
            }
#endif

            var loadObjectAsyncResult = await StorageFileHelper.LoadObjectAsync<AppData>(FILE_NAME, ApplicationData.Current.LocalFolder);
            Current                   = loadObjectAsyncResult.Object;
            Current.ShowLoadingError  = !loadObjectAsyncResult.Success;

            Current.PropertyChanged += async (sender, e) =>
            {
                if (e.PropertyName != nameof(ShowAbout) && e.PropertyName != nameof(ShowMobile))
                {
                    await Current.SaveAsync();
                }
            };
        }
    }
}
