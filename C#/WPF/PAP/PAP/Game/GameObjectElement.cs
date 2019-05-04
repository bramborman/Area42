using System.Windows.Controls;

namespace PAP.Game
{
    public abstract class GameObjectElement : ContentControl
    {
        public double Left
        {
            get { return Canvas.GetLeft(this); }
            set { Canvas.SetLeft(this, value); }
        }
        public double Top
        {
            get { return Canvas.GetTop(this); }
            set { Canvas.SetTop(this, value); }
        }
        public int Priority { get; set; }

        public GameObjectElement()
        {
            GameManager.GameObjects.Add(this);
        }

        public virtual void Start()
        {

        }

        public virtual void Update()
        {

        }
    }
}
