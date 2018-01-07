using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;

namespace Challenges
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            IEnumerable<TypeInfo> challenges = Assembly.GetExecutingAssembly().DefinedTypes.Where(t => t.GetInterface(nameof(IChallenge)) != null);

            while (true)
            {
                Console.Clear();

                foreach (TypeInfo challenge in challenges)
                {
                    Console.WriteLine(challenge.Name);
                }

                Console.Write("Enter number of a selected challenge or 'exit' to exit: ");

                string input = Console.ReadLine();

                if (Regex.IsMatch(input, "^[0-9]{3}$"))
                {
                    Console.Clear();

                    string challengeTypeName = "Challenge" + input;
                    TypeInfo challenge = challenges.First(t => t.Name == challengeTypeName);
                    ((IChallenge)Activator.CreateInstance(challenge.UnderlyingSystemType)).Run();
                }
                else if (string.Equals(input, "exit", StringComparison.InvariantCultureIgnoreCase))
                {
                    break;
                }
            }
        }
    }
}
