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
            IEnumerable<string> challenges = Assembly.GetExecutingAssembly().GetTypes().Where(t => t.GetInterface(nameof(IChallenge)) != null).Select(t => t.Name);

            while (true)
            {
                Console.Clear();

                foreach (string challenge in challenges)
                {
                    Console.WriteLine(challenge);
                }

                Console.Write("Enter number of a selected challenge or 'exit' to exit: ");

                string input = Console.ReadLine();

                if (Regex.IsMatch(input, "^[0-9]{0,3}$"))
                {
                    Console.Clear();
                    
                    Type challengeType = Type.GetType(nameof(Challenges) + ".Challenge" + input.PadLeft(3, '0'));

                    if (challengeType != null)
                    {
                        IChallenge challenge = (IChallenge)Activator.CreateInstance(challengeType);

                        Console.Write(new string('=', Console.WindowWidth));
                        Console.CursorLeft = (Console.WindowWidth - challengeType.Name.Length) / 2;
                        Console.WriteLine(challengeType.Name.ToUpper());
                        Console.WriteLine();
                        Console.WriteLine(challenge.Description);
                        Console.WriteLine(new string('=', Console.WindowWidth));

                        challenge.Run();
                    }
                }
                else if (string.Equals(input, "exit", StringComparison.InvariantCultureIgnoreCase))
                {
                    break;
                }
            }
        }
    }
}
