using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace StorageTools.Modules
{
    public abstract class AModule
    {
        public static IEnumerable<AModule> Modules { get; } = new AModule[]
        {
            new DuplicatesFinderModule(), new FolderComparerModule(), new TimeAttributesCopierModule(), new TreeModule()
        }.OrderBy(m => m.Name);

        protected readonly List<string> paths = new List<string>();

        public abstract string Name { get; }
        public abstract string Description { get; }
        public List<object> Options { get; } = new List<object>();

        public void Run()
        {
            Console.WriteLine(Name);
            Console.WriteLine(Description);
            RunCore();
        }

        protected abstract void RunCore();

        protected string GetPath(PathType pathType)
        {
            do
            {
                Console.Write($"Enter a {pathType.ToString().ToLowerInvariant()} path: ");
            } while (true);

            //TODO: Implement this of course
            //TODO: Show dialog window? (WPF/Forms)
            throw new NotImplementedException(pathType.ToString());


            bool ValidatePath(string path)
            {
                if (pathType == PathType.Volume)
                {
                    if (!Directory.Exists(path))
                    {
                        return false;
                    }

                    if (Path.GetPathRoot())
                }
            }
        }


        protected enum PathType
        {
            Volume,
            Directory,
            File
        }
    }
}
