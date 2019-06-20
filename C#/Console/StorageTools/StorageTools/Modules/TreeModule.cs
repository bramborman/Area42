using StorageTools.Helpers;
using System;
using System.Collections.Generic;

namespace StorageTools.Modules
{
    public sealed class TreeModule : AModule
    {
        public override string Name { get; } = "Tree";
        public override string Description { get; } = "Tree";

        protected override void RunCore()
        {
            Dictionary<Argument, object> arguments = new Dictionary<Argument, object>();

            try
            {
                foreach (string arg in /*args*/ new[] { "" })
                {
                    (Argument argument, object data) argument = (null, null);// Argument.Parse(arg);

                    if (arguments.ContainsKey(argument.argument))
                    {
                        throw new Exception("Argument was specified more than once: " + arg);
                    }

                    arguments.Add(argument.argument, argument.data);
                }
            }
            catch (Exception ewm)
            {
                Console.WriteLine(ewm.Message);
            }

            foreach (KeyValuePair<Argument, object> argument in arguments)
            {

            }

        }
    }
}
