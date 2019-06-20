using System;
using System.Collections.Generic;
using System.Linq;

namespace StorageTools.Helpers
{
    public sealed class Argument
    {
        private readonly bool hasData;
        private readonly Func<string, object> dataParser;

        public string LongName { get; }
        public string ShortName { get; }
        public string Description { get; }
        public object Data { get; private set; }

        public Argument(string longName, string shortName, Func<string, object> dataParser)
        {
            hasData = dataParser != null;
            this.dataParser = dataParser;

            LongName = longName;
            ShortName = shortName;
        }

        public static void AssignDataToArguments(string[] args, IEnumerable<Argument> arguments)
        {
            for (int i = 0; i < args.Length; i++)
            {
                string arg = args[i];

                if (arguments.FirstOrDefault(a => IsValidNameForArgument(a, arg)) is Argument argument)
                {
                    if (argument.hasData)
                    {
                        if (++i == args.Length)
                        {
                            throw new ConsoleArgumentException(arg, ConsoleArgumentException.ArgumentExceptionType.MissingData);
                        }
                        else
                        {
                            try
                            {
                                argument.Data = argument.dataParser(args[i]);
                            }
                            catch (Exception exception)
                            {
                                throw new ConsoleArgumentException(arg, ConsoleArgumentException.ArgumentExceptionType.InvalidData, exception);
                            }
                        }
                    }
                }
                else
                {
                    throw new ConsoleArgumentException(arg, ConsoleArgumentException.ArgumentExceptionType.InvalidName);
                }
            }


            bool IsValidNameForArgument(Argument argument, string str)
            {
                return string.Equals(argument.LongName, str, StringComparison.InvariantCultureIgnoreCase) ||
                       (argument.ShortName != null && string.Equals(argument.ShortName, str, StringComparison.InvariantCultureIgnoreCase));
            }
        }
    }
}
