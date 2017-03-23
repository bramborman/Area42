using System;
using System.IO;

namespace MVC_WebService.App_Core
{
    // This is saving the files locally - on the server side
    public static class Logger
    {
        private const string LOG_DIRECTORY_PATH     = @"C:\MVC_WebService\Logs\";
        private const string LOG_NAVIGATION_PATH    = LOG_DIRECTORY_PATH + "Navigation.log";

        private static readonly object navigationLogLocker = new object();

        public static void OnNavigation(string controllerName, string actionName)
        {
            lock (navigationLogLocker)
            {
                // File must be created before using this
                // StreamWriter file = new StreamWriter(@"C:\MVC_WebService\Logs\navigation.log");
                // file.WriteLine($"{DateTime.Now:HH:mm:ss}: Navigated to controller '{controllerName}'", true);
                // //file.Flush();
                // file.Close();

                EnsureLogDirectoryExists();
                File.AppendAllText(LOG_NAVIGATION_PATH, $"{DateTime.Now:yyyy/MM/dd HH:mm:ss}: Navigated to {controllerName}/{actionName}\n");
            }
        }

        public static string GetNavigationLog()
        {
            lock (navigationLogLocker)
            {
                if (!File.Exists(LOG_NAVIGATION_PATH))
                {
                    return null;
                }

                return File.ReadAllText(LOG_NAVIGATION_PATH);
            }
        }

        private static void EnsureLogDirectoryExists()
        {
            if (!Directory.Exists(LOG_DIRECTORY_PATH))
            {
                Directory.CreateDirectory(LOG_DIRECTORY_PATH);
            }
        }
    }
}