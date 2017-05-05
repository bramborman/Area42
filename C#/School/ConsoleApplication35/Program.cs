using System;
using System.Collections.Generic;
using System.Linq;
using System.Speech.Synthesis;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication35
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            new SpeechSynthesizer().Speak("Die you motherfucker!!!");
        }
    }
}
