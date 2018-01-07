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
                    Type challengeType = challenges.First(t => t.Name == challengeTypeName).UnderlyingSystemType;

                    IChallenge challenge = (IChallenge)Activator.CreateInstance(challengeType);

                    Console.Write(new string('=', Console.WindowWidth));
                    Console.CursorLeft = (Console.WindowWidth - challengeType.Name.Length) / 2;
                    Console.WriteLine(challengeType.Name.ToUpper());
                    Console.WriteLine();
                    Console.WriteLine(challenge.Description);
                    Console.WriteLine(new string('=', Console.WindowWidth));

                    challenge.Run();
                }
                else if (string.Equals(input, "exit", StringComparison.InvariantCultureIgnoreCase))
                {
                    break;
                }
            }
        }
    }
}
