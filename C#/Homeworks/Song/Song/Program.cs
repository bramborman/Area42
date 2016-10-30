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
        const int I1 = 580;
        const int I2 = I1 / 2;
        const int I4 = I1 / 4;

        const int C4  = 262;
        const int Cx4 = 277;
        const int D4  = 294;
        const int Dx4 = 311;
        const int E4  = 330;
        const int F4  = 349;
        const int Fx4 = 370;
        const int G4  = 392;
        const int Gx4 = 415;
        const int A4  = 440;
        const int Ax4 = 466;
        const int H4  = 494;

        const int C5  = 523;
        const int Cx5 = 554;
        const int D5  = 587;
        const int Dx5 = 622;
        const int E5  = 659;
        const int F5  = 698;
        const int Fx5 = 740;
        const int G5  = 784;
        const int Gx5 = 831;
        const int A5  = 880;
        const int Ax5 = 932;
        const int H5  = 988;

        const int C6  = 1109;
        #endregion

        static void Main(string[] args)
        {
            Console.Title = "All star - Mouth Smash";
            Console.CursorVisible = false;
            Stopwatch stopwatch = new Stopwatch();
            SoundPlayer accompaniment = new SoundPlayer(Assembly.GetExecutingAssembly().GetManifestResourceStream("Song.Accompaniment.wav"));

            while (true)
            {
                //Thread.Sleep(60);
                Console.Clear();
                stopwatch.Restart();
                accompaniment.Play();

                WriteNBeep(Fx4, I1, "Some");
                WriteNBeep(Dx5, I2, "bo");
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

                Thread.Sleep(I2 - 50);

                WriteNBeep(Fx4, I2, "I ");
                WriteNBeep(Dx5, I2, "ain't ");
                WriteNBeep(Ax4, I2, "the ");
                WriteNBeep(Ax4, I2, "shar");
                WriteNBeep(Gx4, I2, "pest ");
                WriteNBeep(Gx4, I2, "tool ");
                WriteNBeep(Fx4, I2, "in ");
                WriteNBeep(Fx4, I2, "the ");
                WriteNBeep(Dx4, I1, "she");
                WriteNBeep(Cx4, I1 + 100, "d\n");

                Thread.Sleep(I1 + 100);

                WriteNBeep(Fx4, I2, "She ");
                WriteNBeep(Fx4, I2, "was ");
                WriteNBeep(Dx5, I2, "loo");
                WriteNBeep(Ax4, I2, "king ");
                WriteNBeep(Ax4, I2, "kind ");
                WriteNBeep(Gx4, I2, "of ");
                WriteNBeep(Gx4, I2, "dumb ");
                WriteNBeep(Fx4, I2, "with ");
                WriteNBeep(Fx4, I2, "her ");
                WriteNBeep( H4, I1, "fin");
                WriteNBeep(Ax4, I2, "ger ");
                WriteNBeep(Ax4, I2, "and ");
                WriteNBeep(Gx4, I2, "her ");
                WriteNBeep(Gx4, I2, "thumb\n");
                WriteNBeep(Fx4, I2, "In ");
                WriteNBeep(Fx4, I2, "the ");
                WriteNBeep(Dx5, I1, "shape ");
                WriteNBeep(Ax4, I2, "of ");
                WriteNBeep(Ax4, I2, "an ");
                WriteNBeep(Gx4, I1, "L ");
                WriteNBeep(Fx4, I2, "on ");
                WriteNBeep(Fx4, I2, "her ");
                WriteNBeep(Gx4, I1, "fore");
                WriteNBeep(Dx4, I1 + 100, "head\n\n");

                Thread.Sleep(I1 + 100);

                WriteNBeep(Fx4, I1, "Well ");
                WriteNBeep(Fx4, I4, "the ");
                WriteNBeep(Fx4, I2, "years ");
                WriteNBeep(Fx4, I2, "start ");
                WriteNBeep(Fx4, I4, "co");
                WriteNBeep(Fx4, I4, "ming ");
                WriteNBeep(Fx4, I4, "and ");
                WriteNBeep(Fx4, I4, "they ");
                WriteNBeep(Fx4, I2, "don't ");
                WriteNBeep(Fx4, I2, "stop ");
                WriteNBeep(Fx4, I4, "co");
                WriteNBeep(Fx4, I4, "ming\n");

                Thread.Sleep(I2);

                WriteNBeep(Fx4, I2, "Fed ");
                WriteNBeep(Fx4, I4, "to ");
                WriteNBeep(Fx4, I4, "the ");
                WriteNBeep(Fx4, I2, "rules ");
                WriteNBeep(Fx4, I4, "and ");
                WriteNBeep(Fx4, I4, "I ");
                WriteNBeep(Fx4, I4, "hit ");
                WriteNBeep(Fx4, I4, "the ");
                WriteNBeep(Fx4, I2, "ground ");
                WriteNBeep(Ax4, I4, "run");
                WriteNBeep(Fx4, I4, "ning\n");

                Thread.Sleep(I2);

                WriteNBeep(Ax4, I4, "Didn't ");
                WriteNBeep(Dx5, I4, "make ");
                WriteNBeep(Dx5, I2, "sense ");
                WriteNBeep(Dx5, I2, "not ");
                WriteNBeep( H4, I4, "to ");
                WriteNBeep( H4, I4, "live ");
                WriteNBeep(Ax4, I2, "for ");
                WriteNBeep(Ax4, I2, "fun");
                WriteNBeep(Ax4, I2);
                Thread.Sleep(I4);
                WriteNBeep(Cx4, I4);

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
