using System;
using System.Diagnostics;
using System.Media;
using System.Reflection;
using System.Threading;

namespace Song
{
    class Program
    {
        #region Constants
        const int I1 = 579;
        const int I2 = I1 / 2;
        const int I4 = I1 / 4;
        
        const int Cx4 = 277;
        const int Dx4 = 311;
        const int Fx4 = 370;
        const int Gx4 = 415;
        const int Ax4 = 466;
        const int H4  = 494;
        
        const int Cx5 = 554;
        const int Dx5 = 622;
        #endregion

        static void Main(string[] args)
        {
            Console.Title = "All star - Mouth Smash";
            Console.CursorVisible = false;
            Stopwatch stopwatch = new Stopwatch();
            SoundPlayer accompaniment = new SoundPlayer(Assembly.GetExecutingAssembly().GetManifestResourceStream("Song.Song.wav"));
            accompaniment.Load();

            while (true)
            {
                Thread.Sleep(50);
                Console.Clear();
                stopwatch.Restart();
                //accompaniment.Play(); // DON'T DO THIS!!!

                WriteNBeep(Fx4, I1 + 50, "Some");
                WriteNBeep(Cx5, I2, "bo");
                WriteNBeep(Ax4, I2, "dy ");
                WriteNBeep(Ax4, I1, "once ");
                WriteNBeep(Gx4, I2, "told ");
                WriteNBeep(Fx4, I2, "me ");
                WriteNBeep(Fx4, I2, "the ");
                WriteNBeep( H4, I1, "world ");
                WriteNBeep(Ax4, I2, "is ");
                WriteNBeep(Ax4, I2, "go");
                WriteNBeep(Gx4, I2, "nna ");
                WriteNBeep(Gx4, I2, "roll ");
                WriteNBeep(Fx4, I2, "me\n");

                Thread.Sleep(I2);

                WriteNBeep(Fx4, I2, "I ");
                WriteNBeep(Cx5, I2, "ain't ");
                WriteNBeep(Ax4, I2, "the ");
                WriteNBeep(Ax4, I2, "shar");
                WriteNBeep(Gx4, I2, "pest ");
                WriteNBeep(Gx4, I2, "tool ");
                WriteNBeep(Fx4, I2, "in ");
                WriteNBeep(Fx4, I2, "the ");
                WriteNBeep(Dx4, I1, "she");
                WriteNBeep(Cx4, I1 + 100, "d\n");

                Thread.Sleep(I1 + I4);

                WriteNBeep(Fx4, I2, "She ");
                WriteNBeep(Fx4, I2, "was ");
                WriteNBeep(Cx5, I2, "loo");
                WriteNBeep(Ax4, I2, "king ");
                WriteNBeep(Ax4, I2, "kind ");
                WriteNBeep(Gx4, I2, "of ");
                WriteNBeep(Gx4, I2, "dumb ");
                WriteNBeep(Fx4, I2, "with ");
                WriteNBeep(Fx4, I2, "her ");
                WriteNBeep( H4, I1 - 50, "fin");
                WriteNBeep(Ax4, I2, "ger ");
                WriteNBeep(Ax4, I2, "and ");
                WriteNBeep(Gx4, I2, "her ");
                WriteNBeep(Gx4, I2, "thumb\n");

                WriteNBeep(Fx4, I2, "In ");
                WriteNBeep(Fx4, I2, "the ");
                WriteNBeep(Cx5, I1, "shape ");
                WriteNBeep(Ax4, I2, "of ");
                WriteNBeep(Ax4, I2, "an ");
                WriteNBeep(Gx4, I1, "L ");
                WriteNBeep(Fx4, I2, "on ");
                WriteNBeep(Fx4, I2, "her ");
                WriteNBeep(Gx4, I1, "fore");
                WriteNBeep(Dx4, I1 + 100, "head\n\n");

                Thread.Sleep(I1);

                WriteNBeep(Fx4, I1 - 50, "Well ");
                WriteNBeep(Fx4, I4, "the ");
                WriteNBeep(Fx4, I2, "years ");
                WriteNBeep(Fx4, I2, "start ");
                WriteNBeep(Fx4, I4, "co");
                WriteNBeep(Fx4, I4, "ming ");
                WriteNBeep(Fx4, I4, "and ");
                WriteNBeep(Fx4, I4 , "they ");
                WriteNBeep(Fx4, I2, "don't ");
                WriteNBeep(Fx4, I2, "stop ");
                WriteNBeep(Fx4, I4, "co");
                WriteNBeep(Fx4, I4, "ming\n");

                Thread.Sleep(I2 - 50);

                WriteNBeep(Fx4, I2, "Fed ");
                WriteNBeep(Fx4, I4, "to ");
                WriteNBeep(Fx4, I4, "the ");
                WriteNBeep(Fx4, I2, "rules ");
                WriteNBeep(Fx4, I4, "and ");
                WriteNBeep(Fx4, I4, "I ");
                WriteNBeep(Fx4, I4, "hit ");
                WriteNBeep(Fx4, I4, "the ");
                WriteNBeep(Fx4, I4, "ground ");
                WriteNBeep(Ax4, I4, "run");
                WriteNBeep(Fx4, I4, "ning\n");

                Thread.Sleep(I2);

                WriteNBeep(Ax4, I4, "Didn't ");
                WriteNBeep(Cx5, I4, "make ");
                WriteNBeep(Cx5, I2, "sense ");
                WriteNBeep(Cx5, I2, "not ");
                WriteNBeep(H4, I4, "to ");
                WriteNBeep(H4, I4, "li");
                WriteNBeep(Ax4, I2, "ve ");
                WriteNBeep(Ax4, I2, "for ");
                WriteNBeep(Ax4, I2, "fun\n");

                Thread.Sleep(I4);

                WriteNBeep(Cx4, I4, "Your ");
                WriteNBeep(Ax4, I2, "brain ");
                WriteNBeep(Fx4, I2, "gets ");
                WriteNBeep(Fx4, I2, "smart ");
                WriteNBeep(Fx4, I4, "but ");
                WriteNBeep(Dx4, I4, "your ");
                WriteNBeep(Fx4, I2, "head ");
                WriteNBeep(Fx4, I2, "gets ");
                WriteNBeep(Dx4, I4, "du");
                WriteNBeep(Cx4, I4, "mb\n\n");
                
                Thread.Sleep(I2 - 150);

                WriteNBeep(Ax4, I4, "So ");
                WriteNBeep(Cx5, I2, "much ");
                WriteNBeep(Ax4, I4, "to ");
                WriteNBeep(Dx5, I2, "do ");
                WriteNBeep(Ax4, I4, "so ");
                WriteNBeep(Cx5, I2, "much ");
                WriteNBeep(Ax4, I4, "to ");
                WriteNBeep(Dx5, I2, "see\n");

                WriteNBeep(Ax4, I4, "So ");
                WriteNBeep(Cx5, I2, "what's ");
                WriteNBeep(H4, I2, "wrong ");
                WriteNBeep(Ax4, I2, "with ");
                WriteNBeep(Gx4, I2, "tak");
                WriteNBeep(Gx4, I2, "ing ");
                WriteNBeep(Fx4, I4, "the ");
                WriteNBeep(Gx4, I2, "back ");
                WriteNBeep(Fx4, I2, "streets\n");

                Thread.Sleep(I1 - 150);

                WriteNBeep(Cx4, I4, "You'll ");
                WriteNBeep(Fx4, I4, "ne");
                WriteNBeep(Fx4, I4, "ver ");
                WriteNBeep(Fx4, I2, "know ");
                WriteNBeep(Fx4, I4, "if ");
                WriteNBeep(Fx4, I4, "you ");
                WriteNBeep(Fx4, I2, "don't ");
                WriteNBeep(Fx4, I2, "go\n");

                Thread.Sleep(I1 - 50);

                WriteNBeep(Cx4, I4, "You'll ");
                WriteNBeep(Ax4, I4, "ne");
                WriteNBeep(Fx4, I4, "ver ");
                WriteNBeep(Fx4, I2, "shine ");
                WriteNBeep(Fx4, I4, "if ");
                WriteNBeep(Dx4, I4, "you ");
                WriteNBeep(Dx4, I2, "don't ");
                WriteNBeep(Dx4, I1, "glow\n\n");

                Thread.Sleep(I1);

                WriteNBeep(Ax4, I2, "Hey ");
                WriteNBeep(Fx4, I1, "now ");
                WriteNBeep(Fx4, I4, "you're ");
                WriteNBeep(Dx4, I4, "an ");
                WriteNBeep(Fx4, I2, "All ");
                WriteNBeep(Fx4, I2, "Star ");
                Thread.Sleep(I2);
                WriteNBeep(Fx4, I4, "get ");
                WriteNBeep(Dx4, I4, "your ");
                WriteNBeep(Fx4, I2, "game ");
                WriteNBeep(Fx4, I2, "on, ");
                Thread.Sleep(I2);
                WriteNBeep(Fx4, I4, "go ");
                Thread.Sleep(I2);
                WriteNBeep(Ax4, I1 + I2 - I4, "play\n");

                Thread.Sleep(I4);

                WriteNBeep(Ax4, I2, "Hey ");
                WriteNBeep(Fx4, I1, "now ");
                WriteNBeep(Fx4, I4, "you're ");
                WriteNBeep(Dx4, I4, "an ");
                WriteNBeep(Fx4, I2, "Rock ");
                WriteNBeep(Fx4, I2, "Star ");
                Thread.Sleep(I2);
                WriteNBeep(Fx4, I4, "get ");
                WriteNBeep(Dx4, I4, "the ");
                WriteNBeep(Fx4, I2, "show ");
                WriteNBeep(Fx4, I2, "on ");
                Thread.Sleep(I2);
                WriteNBeep(Fx4, I2, "get ");
                Thread.Sleep(I2);
                WriteNBeep(Ax4, I1 + I2 - I4, "paid\n");

                Thread.Sleep(I4);

                WriteNBeep(Dx4, I1 - 50, "And ");
                Thread.Sleep(I4);
                WriteNBeep(Ax4, I2 + I4, "all ");
                WriteNBeep(Cx5, I4, "that ");
                WriteNBeep( H4, I2, "glit");
                WriteNBeep(Ax4, I2, "ters ");
                WriteNBeep(Gx4, I2, "is ");
                WriteNBeep(Gx4, I2, "go");
                WriteNBeep(Fx4, (2 * I1) - I4, "ld\n");

                Thread.Sleep(I4);

                WriteNBeep(Fx4, I2, "On");
                WriteNBeep(Fx4, I2, "ly ");
                WriteNBeep(Gx4, I2, "shoo");
                WriteNBeep(Fx4, I2, "ting ");
                WriteNBeep(Ax4, I2, "sta");
                WriteNBeep(Gx4, (2 * I2) + I4, "rs ");
                Thread.Sleep(I4);
                WriteNBeep(Gx4, I4, "break ");
                WriteNBeep(Fx4, I1, "the ");
                WriteNBeep(Gx4, I2, "m");
                WriteNBeep(Ax4, I2, "o");
                WriteNBeep(Dx4, 3 * I1, "ld");
                
                accompaniment.Stop();
                stopwatch.Stop();
                Console.WriteLine($"\n\nPlayback ended after {stopwatch.Elapsed.ToString("mm':'ss'.'fff")}");
                Console.Write("Press 'R' to restart or any other key to exit . . .");

                if (char.ToUpper(Console.ReadKey().KeyChar) != 'R')
                {
                    break;
                }
            }
        }

        static void WriteNBeep(int frequency, int duration, string text = "")
        {
            Console.Write(text);
            Console.Beep(frequency, duration);
        }
    }
}
