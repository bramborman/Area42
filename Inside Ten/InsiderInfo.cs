﻿using Newtonsoft.Json;
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
    public sealed class InsiderInfo : NotifyPropertyChangedBase, IEnumerable<BuildInfo>
    {
        private const string FILE_NAME = "InsideTenApi.json";

        public static InsiderInfo Current { get; private set; }
        public static bool ShowLoadingError { get; set; }
        
        public bool IsSuccessfullyLoaded
        {
            get { return (bool)GetValue(); }
            private set { SetValue(value); }
        }
        public bool IsLoading
        {
            get { return (bool)GetValue(); }
            private set { SetValue(value); }
        }
        public DeviceInfo PC { get; }
        public DeviceInfo Mobile { get; }
        public BuildInfo Internal { get; }
        public BuildInfo InternalService { get; }

        public InsiderInfo()
        {
            RegisterProperty(nameof(IsSuccessfullyLoaded), typeof(bool), false);
            RegisterProperty(nameof(IsLoading), typeof(bool), false);

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

        public bool AssignFromInsideTenApi(InsideTenApi insideTenApi)
        {
            bool pcFastChanged                  = PC.Fast.AssignFromInsideTenApiBuildInfo(insideTenApi.pcwif);
            bool pcSlowChanged                  = PC.Slow.AssignFromInsideTenApiBuildInfo(insideTenApi.pcwis);
            bool pcReleasePreviewChanged        = PC.ReleasePreview.AssignFromInsideTenApiBuildInfo(insideTenApi.pcwrp);
            bool mobileFastChanged              = Mobile.Fast.AssignFromInsideTenApiBuildInfo(insideTenApi.mowif);
            bool mobileSlowChanged              = Mobile.Slow.AssignFromInsideTenApiBuildInfo(insideTenApi.mowis);
            bool mobileReleasePreviewChanged    = Mobile.ReleasePreview.AssignFromInsideTenApiBuildInfo(insideTenApi.mowrp);
            bool internalChanged                = Internal.AssignFromInsideTenApiBuildInfo(insideTenApi.@internal);
            bool internalServiceChanged         = InternalService.AssignFromInsideTenApiBuildInfo(insideTenApi.internalservice);

            DebugHelper.OperationInfo(nameof(InsiderInfo), "assigning", true);
            return pcFastChanged || pcSlowChanged || pcReleasePreviewChanged || mobileFastChanged || mobileSlowChanged || mobileReleasePreviewChanged || internalChanged || internalServiceChanged;
        }
        
        public static async Task LoadAsync()
        {
            bool initialLoad = Current == null;
            ShowLoadingError = false;
            
            if (initialLoad)
            {
                Current = new InsiderInfo();
            }

            Current.IsLoading = true;
            
            if (NetworkInformation.GetInternetConnectionProfile()?.GetNetworkConnectivityLevel() == NetworkConnectivityLevel.InternetAccess)
            {
                using (HttpClient httpClient = new HttpClient())
                {
                    string insideTenApiJson = await httpClient.GetStringAsync("https://raw.githubusercontent.com/MehediH/InsideTen/gh-pages/api.json");
                    DebugHelper.OperationInfo("Inside Ten api.json", "downloading", true);

                    if (!string.IsNullOrWhiteSpace(insideTenApiJson))
                    {
                        if (Current.AssignFromInsideTenApi(await Task.Run(() => JsonConvert.DeserializeObject<InsideTenApi>(insideTenApiJson))))
                        {
                            AppData.Current.InsiderInfoLastUpdate = DateTime.Now;
                            System.Diagnostics.Debug.WriteLine($"{nameof(InsiderInfo)} data was updated at {AppData.Current.InsiderInfoLastUpdate:HH:mm:ss}");
                        }

                        Current.IsSuccessfullyLoaded = true;
                        await FileIO.WriteTextAsync(await ApplicationData.Current.LocalFolder.CreateFileAsync(FILE_NAME, CreationCollisionOption.OpenIfExists), insideTenApiJson);
                    }
                }
            }
            else if (initialLoad)
            {
                try
                {
                    StorageFile file = await ApplicationData.Current.LocalFolder.GetFileAsync(FILE_NAME);

                    string json = await FileIO.ReadTextAsync(file);

                    if (!string.IsNullOrWhiteSpace(json))
                    {
                        Current.AssignFromInsideTenApi(await Task.Run(() => JsonConvert.DeserializeObject<InsideTenApi>(json)));
                        Current.IsSuccessfullyLoaded = true;
                    }
                    else
                    {
                        ShowLoadingError = true;
                    }
                }
                catch
                {
                    ShowLoadingError = true;
                }
            }


            Current.IsLoading = false;
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
        private const string BUILD_DEFAULT_VALUE = null;

        private static readonly DelegateCommand _openMoreCommand = new DelegateCommand(async (sender, e) =>
        {
            await Launcher.LaunchUriAsync(new Uri((string)e));
        });

        [JsonIgnore]
        public string DisplayName { get; }
        public string Build
        {
            get { return (string)GetValue(); }
            private set { SetValue(value); }
        }
        public string Version
        {
            get { return (string)GetValue(); }
            private set { SetValue(value); }
        }
        public string More
        {
            get { return (string)GetValue(); }
            private set { SetValue(value); }
        }
        public DateTime ReleaseDate
        {
            get { return (DateTime)GetValue(); }
            private set { SetValue(value); }
        }
        [JsonIgnore]
        public DelegateCommand OpenMoreCommand
        {
            get { return _openMoreCommand; }
        }

        public BuildInfo(string displayName)
        {
            DisplayName = displayName.ToUpper();

            RegisterProperty(nameof(Build), typeof(string), BUILD_DEFAULT_VALUE);
            RegisterProperty(nameof(Version), typeof(string), null);
            RegisterProperty(nameof(More), typeof(string), null);
            RegisterProperty(nameof(ReleaseDate), typeof(DateTime), new DateTime());
        }

        public bool AssignFromInsideTenApiBuildInfo(InsideTenApiBuildInfo insideTenApiBuildInfo)
        {
            // Must compare with default value, otherwise the AppData.InsiderInfoLastUpdate property will be rewrited on app start
            bool changed = Build != insideTenApiBuildInfo.build && Build != BUILD_DEFAULT_VALUE;

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

            return changed;
        }
    }
}
