using UWPHelper.Utilities;

namespace InsideTen
{
    public class InsideInfo : NotifyPropertyChangedBase
    {
        public DeviceInfo PC
        {
            get { return GetValue<DeviceInfo>(nameof(PC)); }
            set { SetValue(nameof(PC), ref value); }
        }
        public DeviceInfo Mobile
        {
            get { return GetValue<DeviceInfo>(nameof(Mobile)); }
            set { SetValue(nameof(Mobile), ref value); }
        }
        public BuildInfo Internal
        {
            get { return GetValue<BuildInfo>(nameof(Internal)); }
            set { SetValue(nameof(Internal), ref value); }
        }
        public BuildInfo InternalServicing
        {
            get { return GetValue<BuildInfo>(nameof(InternalServicing)); }
            set { SetValue(nameof(InternalServicing), ref value); }
        }

        public InsideInfo()
        {
            RegisterProperty(nameof(PC), typeof(DeviceInfo), null);
            RegisterProperty(nameof(Mobile), typeof(DeviceInfo), null);
            RegisterProperty(nameof(Internal), typeof(BuildInfo), null);
            RegisterProperty(nameof(InternalServicing), typeof(BuildInfo), null);
        }

        public class BuildInfo : NotifyPropertyChangedBase
        {
            public string Build
            {
                get { return GetValue<string>(nameof(Build)); }
                set { SetValue(nameof(Build), ref value); }
            }
            public string Version
            {
                get { return GetValue<string>(nameof(Version)); }
                set { SetValue(nameof(Version), ref value); }
            }
            public string More
            {
                get { return GetValue<string>(nameof(More)); }
                set { SetValue(nameof(More), ref value); }
            }
            public string ReleaseDate
            {
                get { return GetValue<string>(nameof(ReleaseDate)); }
                set { SetValue(nameof(ReleaseDate), ref value); }
            }

            public BuildInfo()
            {
                RegisterProperty(nameof(Build), typeof(string), null);
                RegisterProperty(nameof(Version), typeof(string), null);
                RegisterProperty(nameof(More), typeof(string), null);
                RegisterProperty(nameof(ReleaseDate), typeof(string), null);
            }
        }

        public class DeviceInfo : NotifyPropertyChangedBase
        {
            public BuildInfo Fast
            {
                get { return GetValue<BuildInfo>(nameof(Fast)); }
                set { SetValue(nameof(Fast), ref value); }
            }
            public BuildInfo Slow
            {
                get { return GetValue<BuildInfo>(nameof(Slow)); }
                set { SetValue(nameof(Slow), ref value); }
            }
            public BuildInfo ReleasePreview
            {
                get { return GetValue<BuildInfo>(nameof(ReleasePreview)); }
                set { SetValue(nameof(ReleasePreview), ref value); }
            }

            public DeviceInfo()
            {
                RegisterProperty(nameof(Fast), typeof(BuildInfo), null);
                RegisterProperty(nameof(Slow), typeof(BuildInfo), null);
                RegisterProperty(nameof(ReleasePreview), typeof(BuildInfo), null);
            }
        }
    }
}