using StorageTools.Helpers;
using StorageTools.Modules;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace StorageTools
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Initialize(args);

            while (true)
            {
                Menu menu = new Menu("\nSelect the module you'd like to run");
                menu.Items.AddRange(AModule.Modules.Select(m => new MenuItem(m.Name, m.Run)));
                menu.Show();
            }
        }

        private static void Initialize(string[] args)
        {
            Console.InputEncoding = Encoding.UTF8;
            Console.OutputEncoding = Encoding.UTF8;

            IEnumerable<Argument> arguments = new Argument[]
            {
                new Argument("--quiet", "-q", null),
                new Argument("--help", "-h", null),
                new Argument("--hidden", null, null),
                new Argument("--root", "-r", str =>
                {
                    string[] splits = str.Split(',');

                    foreach (string split in splits)
                    {
                        if (!Directory.Exists(split))
                        {
                            throw new DirectoryNotFoundException($"The directory specified as root ({split}) was not found.");
                        }
                    }

                    return splits;
                })
            };

            Argument.AssignDataToArguments(args, arguments);

            Assembly assembly = Assembly.GetExecutingAssembly();
            AssemblyName assemblyName = assembly.GetName();

            Console.WriteLine(assemblyName.Name + " v" + assemblyName.Version.ToString(3));
            Console.WriteLine(assembly.GetCustomAttribute<AssemblyCopyrightAttribute>().Copyright);
        }
    }
}
