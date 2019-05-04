using System;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media.Animation;

namespace PAP
{
    public static class Helpers
    {
        public static void SetAnimationKeyFrameValue(TimelineGroup timelineGroup, int animationIndex, int keyFrameIndex, double value)
        {
            ((DoubleAnimationUsingKeyFrames)timelineGroup.Children[animationIndex]).KeyFrames[keyFrameIndex].Value = value;
        }

        public static Task RunStoryboardAsync(string resourceName)
        {
            return RunStoryboardAsync(resourceName, Application.Current.Resources);
        }

        public static Task RunStoryboardAsync(string resourceName, FrameworkElement containingObject)
        {
            return RunStoryboardAsync(resourceName, Application.Current.Resources, containingObject);
        }

        public static Task RunStoryboardAsync(string resourceName, ResourceDictionary resourceDictionary)
        {
            return RunStoryboardAsync(resourceName, resourceDictionary, null);
        }

        public static Task RunStoryboardAsync(string resourceName, ResourceDictionary resourceDictionary, FrameworkElement containingObject)
        {
            return RunStoryboardAsync((Storyboard)resourceDictionary[resourceName], containingObject);
        }

        public static Task RunStoryboardAsync(Storyboard storyboard)
        {
            return RunStoryboardAsync(storyboard, null);
        }

        public static Task RunStoryboardAsync(Storyboard storyboard, FrameworkElement containingObject)
        {
            TaskCompletionSource<object> tcs = new TaskCompletionSource<object>();

            if (storyboard.IsFrozen)
            {
                storyboard = storyboard.Clone();
            }

            storyboard.Completed += Storyboard_Completed;

            if (containingObject == null)
            {
                storyboard.Begin();
            }
            else
            {
                storyboard.Begin(containingObject);
            }

            return tcs.Task;


            void Storyboard_Completed(object sender, EventArgs e)
            {
                storyboard.Completed -= Storyboard_Completed;
                tcs.SetResult(null);
            }
        }
    }
}
