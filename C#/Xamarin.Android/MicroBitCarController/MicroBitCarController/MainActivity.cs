using Android.App;
using Android.Widget;
using Android.OS;
using Android;
using Android.Content.PM;
using Android.Runtime;

namespace MicroBitCarController
{
    [Activity(Label = "MicroBitCarController", MainLauncher = true)]
    public sealed class MainActivity : Activity
    {
        private const int PERMISSION_REQUEST_ID_COARSE_LOCATION = 0;

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            SetContentView(Resource.Layout.Main);

            RequestPermissions(new string[] { Manifest.Permission.AccessCoarseLocation }, 0);
        }

        public override void OnRequestPermissionsResult(int requestCode, string[] permissions, [GeneratedEnum] Permission[] grantResults)
        {
            if (requestCode != 0)
            {
                base.OnRequestPermissionsResult(requestCode, permissions, grantResults);
            }
            else
            {

            }
        }
    }
}

