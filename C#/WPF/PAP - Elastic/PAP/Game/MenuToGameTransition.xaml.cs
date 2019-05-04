using System;
using System.Threading.Tasks;
using System.Windows.Media.Animation;

namespace PAP.Game
{
    public sealed partial class MenuToGameTransition : Page
    {
        private readonly Storyboard flyWindowResizeAnimation;

        public static MenuToGameTransition Instance { get; } = new MenuToGameTransition();

        private MenuToGameTransition()
        {
            InitializeComponent();

            flyWindowResizeAnimation = ((Storyboard)MainWindow.Instance.Resources["ResizeAnimation"]).Clone();

            ParallelTimeline flyWindowResizeAnimationAddition = (ParallelTimeline)Resources["FlyWindowResizeAnimationAddition"];
            Helpers.SetAnimationKeyFrameValue(flyWindowResizeAnimationAddition, 0, 0, (GamePage.requestedSize.Width - RequestedSize.Width) / 2d);
            Helpers.SetAnimationKeyFrameValue(flyWindowResizeAnimationAddition, 1, 0, (GamePage.requestedSize.Height - RequestedSize.Height) / 2d);

            flyWindowResizeAnimation.Children.Add(flyWindowResizeAnimationAddition);
        }

        public override void OnNavigatingTo(bool animate, Type previousPageType)
        {
            // Overriden to prevent execution of the base method
        }

        public override async Task OnNavigatedToAsync(bool animate, Type previousPageType)
        {
            await MainWindow.Instance.ResizeAsync(GamePage.requestedSize, flyWindowResizeAnimation);

            const double PLANE_BOTTOM_OFFSET = 16d;

            Storyboard flyAnimation = (Storyboard)Resources["FlyAnimation"];
            Helpers.SetAnimationKeyFrameValue(flyAnimation, 0, 0,  (-ActualHeight - plane.ActualHeight) / 2d);
            Helpers.SetAnimationKeyFrameValue(flyAnimation, 1, 0,  ( ActualHeight + plane.ActualHeight) / 2d);
            Helpers.SetAnimationKeyFrameValue(flyAnimation, 2, 0, (( ActualHeight - plane.ActualHeight) / 2d) - PLANE_BOTTOM_OFFSET);

            await Helpers.RunStoryboardAsync(flyAnimation);
            //GamePage.Instance.ShowAnimated(plane.ActualWidth, plane.ActualHeight, (ActualWidth - plane.ActualWidth) / 2d, ActualHeight - plane.ActualHeight - PLANE_BOTTOM_OFFSET);
        }
    }
}
