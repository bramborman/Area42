using System;
using System.Collections;
using System.Collections.Generic;
using UWPHelper.Utilities;
using Windows.ApplicationModel.Resources;
using Windows.System;

namespace InsideTen
{
    public sealed class InsiderInfo
    {
        public static InsiderInfo Current { get; private set; }

        public DeviceInfo PC { get; }
        public DeviceInfo Mobile { get; }
        public BuildInfo Internal { get; }
        public BuildInfo InternalServicing { get; }

        public InsiderInfo()
        {
            ResourceLoader resourceLoader = ResourceLoader.GetForViewIndependentUse();

            PC                  = new DeviceInfo();
            Mobile              = new DeviceInfo();
            Internal            = new BuildInfo(resourceLoader.GetString("InternalRing"));
            InternalServicing   = new BuildInfo(resourceLoader.GetString("InternalServicingRing"));
        }

        public static void CreateSampleData()
        {
            Current = new InsiderInfo();

            Current.PC.Fast.Build = "14986";
            Current.PC.Fast.Version = "Redstone 2";
            Current.PC.Fast.More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/";
            Current.PC.Fast.ReleaseDate = new DateTime(2016, 12, 16);

            Current.PC.Slow.Build = "14986";
            Current.PC.Slow.Version = "Redstone 2";
            Current.PC.Slow.More = "";//"https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/";
            Current.PC.Slow.ReleaseDate = new DateTime(2016, 12, 16);

            Current.PC.ReleasePreview.Build = "14986";
            Current.PC.ReleasePreview.Version = "Redstone 2";
            Current.PC.ReleasePreview.More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/";
            Current.PC.ReleasePreview.ReleaseDate = new DateTime(2016, 12, 16);

            Current.Mobile.Fast.Build = "14986";
            Current.Mobile.Fast.Version = "Redstone 2";
            Current.Mobile.Fast.More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/";
            Current.Mobile.Fast.ReleaseDate = new DateTime(2016, 12, 16);

            Current.Mobile.Slow.Build = "14986";
            Current.Mobile.Slow.Version = "Redstone 2";
            Current.Mobile.Slow.More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/";
            Current.Mobile.Slow.ReleaseDate = new DateTime(2016, 12, 16);

            Current.Mobile.ReleasePreview.Build = "14986";
            Current.Mobile.ReleasePreview.Version = "Redstone 2";
            Current.Mobile.ReleasePreview.More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/";
            Current.Mobile.ReleasePreview.ReleaseDate = new DateTime(2016, 12, 16);

            Current.Internal.Build = "14986";
            Current.Internal.Version = "Redstone 2";
            Current.Internal.More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/";
            Current.Internal.ReleaseDate = new DateTime(2016, 12, 16);

            Current.InternalServicing.Build = "14986";
            Current.InternalServicing.Version = "Redstone 2";
            Current.InternalServicing.More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/";
            Current.InternalServicing.ReleaseDate = new DateTime(2016, 12, 16);
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
    }
}
