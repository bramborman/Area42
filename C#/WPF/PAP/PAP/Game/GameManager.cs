using System.Collections.Generic;
using System.Timers;

namespace PAP.Game
{
    public static class GameManager
    {
        private static readonly Timer timer = new Timer(0.1d);

        public static SortedSet<GameObjectElement> GameObjects { get; } = new SortedSet<GameObjectElement>(new GameObjectPriorityComparer());

        static GameManager()
        {
            timer.Elapsed += Update;
        }

        public static void Start()
        {
            timer.Start();
        }

        public static void Pause()
        {
            Stop();
            GamePage.Instance.ShowPauseMenu();
        }

        public static void Resume()
        {
            Start();
        }

        public static void Stop()
        {
            timer.Stop();
        }

        private static void Update(object sender, ElapsedEventArgs e)
        {
            foreach (GameObjectElement gameObject in GameObjects)
            {
                gameObject.Dispatcher.Invoke(gameObject.Update);
            }
        }


        private sealed class GameObjectPriorityComparer : IComparer<GameObjectElement>
        {
            public int Compare(GameObjectElement x, GameObjectElement y)
            {
                return x.Priority.CompareTo(y.Priority);
            }
        }
    }
}
