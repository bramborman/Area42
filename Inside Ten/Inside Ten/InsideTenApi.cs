namespace InsideTen
{
#pragma warning disable IDE1006 // Naming Styles
    public sealed class InsideTenApi
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

    public sealed class InsideTenApiBuildInfo
    {
        public string build { get; set; }
        public string version { get; set; }
        public string more { get; set; }
        public string release_date { get; set; }
    }
#pragma warning restore IDE1006 // Naming Styles
}
