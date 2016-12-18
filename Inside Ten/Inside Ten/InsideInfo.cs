using UWPHelper.Utilities;

namespace InsideTen
{
    public sealed class InsiderInfo : NotifyPropertyChangedBase
    {
        public static InsiderInfo Current { get; private set; }

        public DeviceInfo PC
        {
            get { return (DeviceInfo)GetValue(nameof(PC)); }
            set { SetValue(nameof(PC), ref value); }
        }
        public DeviceInfo Mobile
        {
            get { return (DeviceInfo)GetValue(nameof(Mobile)); }
            set { SetValue(nameof(Mobile), ref value); }
        }
        public BuildInfo Internal
        {
            get { return (BuildInfo)GetValue(nameof(Internal)); }
            set { SetValue(nameof(Internal), ref value); }
        }
        public BuildInfo InternalServicing
        {
            get { return (BuildInfo)GetValue(nameof(InternalServicing)); }
            set { SetValue(nameof(InternalServicing), ref value); }
        }

        public InsiderInfo()
        {
            RegisterProperty(nameof(PC), typeof(DeviceInfo), null);
            RegisterProperty(nameof(Mobile), typeof(DeviceInfo), null);
            RegisterProperty(nameof(Internal), typeof(BuildInfo), null);
            RegisterProperty(nameof(InternalServicing), typeof(BuildInfo), null);
        }

        public static void CreateExampleData()
        {
            Current = new InsiderInfo();
            Current.PC = new DeviceInfo();
            Current.PC.Fast = new BuildInfo("Fast") { Build = "14986.0", Version = "Redstone 2", ReleaseDate = "12/06/2016", More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/" };
            Current.PC.Slow = new BuildInfo("Slow") { Build = "14986.0", Version = "Redstone 2", ReleaseDate = "12/06/2016", More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/" };
            Current.PC.ReleasePreview = new BuildInfo("Release preview") { Build = "14986.0", Version = "Redstone 2", ReleaseDate = "12/06/2016", More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/" };
            Current.Mobile = new DeviceInfo();
            Current.Mobile.Fast = new BuildInfo("Fast") { Build = "14986.0", Version = "Redstone 2", ReleaseDate = "12/06/2016", More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/" };
            Current.Mobile.Slow = new BuildInfo("Slow") { Build = "14986.0", Version = "Redstone 2", ReleaseDate = "12/06/2016", More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/" };
            Current.Mobile.ReleasePreview = new BuildInfo("Release preview") { Build = "14986.0", Version = "Redstone 2", ReleaseDate = "12/06/2016", More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/" };
            Current.Internal = new BuildInfo("Internal") { Build = "14986.0", Version = "Redstone 2", ReleaseDate = "12/06/2016", More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/" };
            Current.InternalServicing = new BuildInfo("Internal servicing") { Build = "14986.0", Version = "Redstone 2", ReleaseDate = "12/06/2016", More = "https://mspoweruser.com/build-14393-479-windows-10-rolling-insiders-pc-mobile/" };
        }
    }

    public sealed class DeviceInfo : NotifyPropertyChangedBase
    {
        public BuildInfo Fast
        {
            get { return (BuildInfo)GetValue(nameof(Fast)); }
            set { SetValue(nameof(Fast), ref value); }
        }
        public BuildInfo Slow
        {
            get { return (BuildInfo)GetValue(nameof(Slow)); }
            set { SetValue(nameof(Slow), ref value); }
        }
        public BuildInfo ReleasePreview
        {
            get { return (BuildInfo)GetValue(nameof(ReleasePreview)); }
            set { SetValue(nameof(ReleasePreview), ref value); }
        }

        public DeviceInfo()
        {
            RegisterProperty(nameof(Fast), typeof(BuildInfo), null);
            RegisterProperty(nameof(Slow), typeof(BuildInfo), null);
            RegisterProperty(nameof(ReleasePreview), typeof(BuildInfo), null);
        }
    }

    public sealed class BuildInfo : NotifyPropertyChangedBase
    {
        internal string DisplayName { get; }

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
        public string ReleaseDate
        {
            get { return (string)GetValue(nameof(ReleaseDate)); }
            set { SetValue(nameof(ReleaseDate), ref value); }
        }

        public BuildInfo(string displayName)
        {
            DisplayName = displayName.ToUpper();

            RegisterProperty(nameof(Build), typeof(string), null);
            RegisterProperty(nameof(Version), typeof(string), null);
            RegisterProperty(nameof(More), typeof(string), null);
            RegisterProperty(nameof(ReleaseDate), typeof(string), null);
        }
    }
}
