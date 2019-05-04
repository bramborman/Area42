using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;

namespace Tree
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Dictionary<Argument, object> arguments = ParseArgs();

            foreach (KeyValuePair<Argument, object> argument in arguments)
            {

            }

            Console.ReadLine();


            Dictionary<Argument, object> ParseArgs()
            {
                Dictionary<Argument, object> output = new Dictionary<Argument, object>();

                try
                {
                    foreach (string arg in args)
                    {
                        (Argument argument, object data) argument = Argument.Parse(arg);

                        if (output.ContainsKey(argument.argument))
                        {
                            throw new ExceptionWithMessage("Argument was specified more than once: " + arg);
                        }

                        output.Add(argument.argument, argument.data);
                    }
                }
                catch (ExceptionWithMessage ewm)
                {
                    Console.ForegroundColor = ConsoleColor.Red;

                    Console.WriteLine(ewm.Message);
                    Console.Write("Press any key to exit . . .");
                    Console.ReadKey(true);

                    Environment.Exit(1);
                    throw new NotImplementedException();
                }

                return output;
            }
        }

        private sealed class Argument
        {
            private delegate bool ArgumentDataParser(string str, out object data);
            
            private static readonly StringComparer stringComparer = StringComparer.InvariantCultureIgnoreCase;
            private static readonly HashSet<Argument> arguments = new HashSet<Argument>();

            public static Argument Root { get; } = new Argument(new HashSet<string>() { "--root", "-r" }, RootsParser);
            public static Argument Hidden { get; } = new Argument(new HashSet<string>() { "--hidden", "-H" }, null);
            public static Argument Help { get; } = new Argument(new HashSet<string>() { "--help", "-h" }, null);

            private readonly ArgumentDataParser dataParser;

            public HashSet<string> Names { get; }
            public bool HasData { get; }

            private Argument(HashSet<string> names, ArgumentDataParser dataParser)
            {
                Names = names;
                HasData = dataParser != null;
                this.dataParser = dataParser;

                arguments.Add(this);
            }

            public static (Argument argument, object data) Parse(string str)
            {
                if (!str.StartsWith('-'))

                (Argument argument, object data) output = (null, null);













                bool treatNextArgumentAsData = false;

                if (arguments.Any(a => a.HasData && a.Names.Contains(str, stringComparer)))
                {
                    treatNextArgumentAsData = true;
                }
                
                //TODO: Parse data

                if ((str[0] != '/' && str[0] != '-') || !TryParseArgName())
                {
                    throw new ExceptionWithMessage(null);
                }

                if (requiredPartsCount == 2 && !output.argument.dataParser(argParts[1], out output.data))
                {
                    throw new ExceptionWithMessage(null);
                }

                return output;


                bool TryParseArgName()
                {
                    output.argument = arguments.FirstOrDefault(a => a.Names.Contains(argParts[0], stringComparer));
                    return output.argument != null;
                }
            }

            private static bool RootsParser(string str, out object data)
            {
                data = null;

                if (string.IsNullOrWhiteSpace(str))
                {
                    return false;
                }

                string[] splits = str.Split(',');

                if (splits.Length == 0)
                {
                    return false;
                }

                foreach (string split in splits)
                {
                    if (!Directory.Exists(split))
                    {
                        return false;
                    }
                }

                data = splits;
                return true;
            }
        }


        [Serializable]
        public sealed class ExceptionWithMessage : Exception
        {
            public ExceptionWithMessage(string message) : base(message)
            {

            }

            private ExceptionWithMessage(SerializationInfo info, StreamingContext context) : base(info, context)
            {

            }
        }
    }
}
