using System.Windows.Input;

namespace PAP.Game
{
    public sealed class Plane : GameObjectElement
    {
        private const double STEP = 2d;

        public override void Start()
        {
            base.Start();
        }

        public override void Update()
        {
            base.Update();

            if (Keyboard.IsKeyDown(Key.Escape))
            {
                GameManager.Pause();
                return;
            }

            bool leftDown = Keyboard.IsKeyDown(Key.Left);
            bool rightDown = Keyboard.IsKeyDown(Key.Right);

            if (leftDown && !rightDown)
            {
                Left -= STEP;
            }
            else if (rightDown && !leftDown)
            {
                Left += STEP;
            }
        }
    }
}
