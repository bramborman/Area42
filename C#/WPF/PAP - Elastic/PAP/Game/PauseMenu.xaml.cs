using System;
using System.Windows;
using System.Windows.Media.Animation;

namespace PAP.Game
{
    public sealed partial class PauseMenu : Page
    {
        public static PauseMenu Instance { get; } = new PauseMenu();

        private PauseMenu()
        {
            InitializeComponent();
        }

        public void ShowAnimated()
        {
            Opacity = 0d;
            Visibility = Visibility.Visible;
            ((Storyboard)Application.Current.Resources["OpacityShowingAnimation"]).Begin(this);
        }

        public void CloseAnimated()
        {
            Storyboard opacityHidingAnimation = ((Storyboard)Application.Current.Resources["OpacityHidingAnimation"]).Clone();
            opacityHidingAnimation.Completed += OpacityHidingAnimation_Completed;
            opacityHidingAnimation.Begin(this);


            void OpacityHidingAnimation_Completed(object sender2, EventArgs e2)
            {
                opacityHidingAnimation.Completed -= OpacityHidingAnimation_Completed;
                Visibility = Visibility.Collapsed;
            }
        }
    }
}
