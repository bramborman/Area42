using System.IO;

namespace MVC_WebService.App_Core
{
    // This is saving the files locally - on the server side
    public static class GalleryCache
    {
        private const string CACHE_DIRECTORY_PATH = @"C:\MVC_WebService\GalleryCache\";

        private static readonly object cacheFolderFileLocker = new object();

        public static void SaveImage(int id, byte[] imageData)
        {
            lock (cacheFolderFileLocker)
            {
                if (!Directory.Exists(CACHE_DIRECTORY_PATH))
                {
                    Directory.CreateDirectory(CACHE_DIRECTORY_PATH);
                }

                // using (BinaryWriter writer = new BinaryWriter(File.Open(GetImagePath(id), FileMode.OpenOrCreate)))
                // {
                //     writer.Write(imageData);
                // }

                File.WriteAllBytes(GetImageFilePath(id), imageData);
            }
        }

        public static byte[] ReadImage(int id)
        {
            lock (cacheFolderFileLocker)
            {
                string filePath = GetImageFilePath(id);

                if (!File.Exists(filePath))
                {
                    return null;
                }

                return File.ReadAllBytes(filePath);
            }
        }

        private static string GetImageFilePath(int id)
        {
            return CACHE_DIRECTORY_PATH + id;
        }

        public static string[] GetCachedFileNames()
        {
            return Directory.GetFiles(CACHE_DIRECTORY_PATH);
        }
    }
}