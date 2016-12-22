using Newtonsoft.Json;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Http;
using System.Threading.Tasks;
using UWPHelper.Utilities;
using Windows.ApplicationModel.Resources;
using Windows.Networking.Connectivity;
using Windows.Storage;
using Windows.System;

namespace InsideTen
{
    public sealed class InsiderInfo : IEnumerable<BuildInfo>
    {
        private const string FILE_NAME = "InsideTenApi.json";

        public static InsiderInfo Current { get; private set; }
        public static bool ShowLoadingError { get; set; }

        internal bool ShowInternetConnectionError { get; set; }

        public DeviceInfo PC { get; }
        public DeviceInfo Mobile { get; }
        public BuildInfo Internal { get; }
        public BuildInfo InternalService { get; }

        public InsiderInfo()
        {
            ResourceLoader resourceLoader = ResourceLoader.GetForViewIndependentUse();

            PC              = new DeviceInfo();
            Mobile          = new DeviceInfo();
            Internal        = new BuildInfo(resourceLoader.GetString("InternalRing"));
            InternalService = new BuildInfo(resourceLoader.GetString("InternalServiceRing"));
        }

        public IEnumerator<BuildInfo> GetEnumerator()
        {
            yield return Internal;
            yield return InternalService;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public void AssignFromInsideTenApi(InsideTenApi insideTenApi)
        {
            PC.Fast.AssignFromInsideTenApiBuildInfo(insideTenApi.pcwif);
            PC.Slow.AssignFromInsideTenApiBuildInfo(insideTenApi.pcwis);
            PC.ReleasePreview.AssignFromInsideTenApiBuildInfo(insideTenApi.pcwrp);

            Mobile.Fast.AssignFromInsideTenApiBuildInfo(insideTenApi.mowif);
            Mobile.Slow.AssignFromInsideTenApiBuildInfo(insideTenApi.mowis);
            Mobile.ReleasePreview.AssignFromInsideTenApiBuildInfo(insideTenApi.mowrp);

            Internal.AssignFromInsideTenApiBuildInfo(insideTenApi.@internal);
            InternalService.AssignFromInsideTenApiBuildInfo(insideTenApi.internalservice);
        }
        
        public static async Task LoadAsync()
        {
            bool initialLoad     = Current == null;
            bool downloadSuccess = false;

            if (initialLoad)
            {
                Current = new InsiderInfo();
            }
            
            if (NetworkInformation.GetInternetConnectionProfile().GetNetworkConnectivityLevel() == NetworkConnectivityLevel.InternetAccess)
            {
                using (HttpClient httpClient = new HttpClient())
                {
                    string insideTenApiJson = await httpClient.GetStringAsync("https://raw.githubusercontent.com/MehediH/InsideTen/gh-pages/api.json");

                    if (!string.IsNullOrWhiteSpace(insideTenApiJson))
                    {
                        Current.AssignFromInsideTenApi(await Task.Run(() => JsonConvert.DeserializeObject<InsideTenApi>(insideTenApiJson)));
                        downloadSuccess = true;

                        await FileIO.WriteTextAsync(await ApplicationData.Current.LocalFolder.CreateFileAsync(FILE_NAME, CreationCollisionOption.OpenIfExists), insideTenApiJson);
                    }
                }
            }
            else if (initialLoad)
            {
                var loadObjectAsyncResult = await StorageFileHelper.LoadObjectAsync<InsideTenApi>(FILE_NAME, ApplicationData.Current.LocalFolder);
                ShowLoadingError    = !loadObjectAsyncResult.Success;

                if (loadObjectAsyncResult.Success)
                {
                    Current.AssignFromInsideTenApi(loadObjectAsyncResult.Object);
                }
            }

            Current.ShowInternetConnectionError = !downloadSuccess;
        }
    }

    public sealed class DeviceInfo : IEnumerable<BuildInfo>
    {
        public BuildInfo Fast { get; }
        public BuildInfo Slow { get; }
        public BuildInfo ReleasePreview { get; }

        public DeviceInfo()
        {
            ResourceLoader resourceLoader = ResourceLoader.GetForViewIndependentUse();

            Fast            = new BuildInfo(resourceLoader.GetString("FastRing"));
            Slow            = new BuildInfo(resourceLoader.GetString("SlowRing"));
            ReleasePreview  = new BuildInfo(resourceLoader.GetString("ReleasePreviewRing"));
        }

        public IEnumerator<BuildInfo> GetEnumerator()
        {
            yield return Fast;
            yield return Slow;
            yield return ReleasePreview;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }

    public sealed class BuildInfo : NotifyPropertyChangedBase
    {
        private static readonly DelegateCommand _openMoreCommand = new DelegateCommand(async (sender, e) =>
        {
            await Launcher.LaunchUriAsync(new Uri((string)e));
        });

        internal string DisplayName { get; }

        public DelegateCommand OpenMoreCommand
        {
            get { return _openMoreCommand; }
        }

        public string Build
        {
            get { return (string)GetValue(nameof(Build)); }
            set { SetValue(nameof(Build), ref value); }
        }
        public string Version
        {
            get { return (string)GetValue(nameof(Version)); }
            set { SetValue(nameof(Version), ref value); }
        }
        public string More
        {
            get { return (string)GetValue(nameof(More)); }
            set { SetValue(nameof(More), ref value); }
        }
        public DateTime ReleaseDate
        {
            get { return (DateTime)GetValue(nameof(ReleaseDate)); }
            set { SetValue(nameof(ReleaseDate), ref value); }
        }

        public BuildInfo(string displayName)
        {
            DisplayName = displayName.ToUpper();

            RegisterProperty(nameof(Build), typeof(string), null);
            RegisterProperty(nameof(Version), typeof(string), null);
            RegisterProperty(nameof(More), typeof(string), null);
            RegisterProperty(nameof(ReleaseDate), typeof(DateTime), new DateTime());
        }

        public void AssignFromInsideTenApiBuildInfo(InsideTenApiBuildInfo insideTenApiBuildInfo)
        {
            Build   = insideTenApiBuildInfo.build;
            Version = insideTenApiBuildInfo.version;
            More    = insideTenApiBuildInfo.more;

            try
            {
                ReleaseDate = DateTime.Parse(insideTenApiBuildInfo.release_date.Replace("st", "").Replace("nd", "").Replace("rd", "").Replace("th", ""));
            }
            catch
            {
#if DEBUG
                throw;
#else
                ReleaseDate = DateTime.Now;
#endif
            }
        }
    }

    public class InsideTenApi
    {
        public InsideTenApiBuildInfo pcwrp { get; set; }
        public InsideTenApiBuildInfo pcwif { get; set; }
        public InsideTenApiBuildInfo pcwis { get; set; }
        public InsideTenApiBuildInfo mowrp { get; set; }
        public InsideTenApiBuildInfo mowif { get; set; }
        public InsideTenApiBuildInfo mowis { get; set; }
        public InsideTenApiBuildInfo @internal { get; set; }
        public InsideTenApiBuildInfo internalservice { get; set; }
    }

    public class InsideTenApiBuildInfo
    {
        public string build { get; set; }
        public string version { get; set; }
        public string more { get; set; }
        public string release_date { get; set; }
    }
}
