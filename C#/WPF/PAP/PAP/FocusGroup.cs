using System.Collections.Generic;
using System.Windows;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;

namespace PAP
{
    public static class FocusGroup
    {
        private static readonly Storyboard blurAnimation = (Storyboard)Application.Current.Resources["FocusGroupBlurAnimation"];
        private static readonly Storyboard blurReverseAnimation = (Storyboard)Application.Current.Resources["FocusGroupBlurReverseAnimation"];
        private static readonly Dictionary<string, HashSet<FrameworkElement>> groups = new Dictionary<string, HashSet<FrameworkElement>>();
        
        public static readonly DependencyProperty NameProperty = DependencyProperty.RegisterAttached("Name", typeof(string), typeof(FocusGroup), new FrameworkPropertyMetadata(null, NamePropertyChanged));
        
        private static void NamePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            FrameworkElement element = (FrameworkElement)d;
            string oldName = (string)e.OldValue;
            string newName = (string)e.NewValue;

            if (!string.IsNullOrWhiteSpace(oldName))
            {
                HashSet<FrameworkElement> group = groups[oldName];
                group.Remove(element);

                if (group.Count == 0)
                {
                    groups.Remove(oldName);
                }

                element.GotFocus -= Element_InFocus;
                element.LostFocus -= Element_OutOfFocus;
                element.MouseEnter -= Element_InFocus;
                element.MouseLeave -= Element_OutOfFocus;
                element.Effect = null;
            }

            if (!string.IsNullOrWhiteSpace(newName))
            {
                if (!groups.ContainsKey(newName))
                {
                    groups.Add(newName, new HashSet<FrameworkElement>());
                }

                groups[newName].Add(element);

                element.Effect = new BlurEffect()
                {
                    Radius = 0d
                };

                element.GotFocus += Element_InFocus;
                element.LostFocus += Element_OutOfFocus;
                element.MouseEnter += Element_InFocus;
                element.MouseLeave += Element_OutOfFocus;
            }
        }

        public static string GetName(FrameworkElement element)
        {
            return (string)element.GetValue(NameProperty);
        }

        public static void SetName(FrameworkElement element, string name)
        {
            element.SetValue(NameProperty, name);
        }
        
        private static void Element_InFocus(object sender, object e)
        {
            FrameworkElement senderElement = (FrameworkElement)sender;

            if (senderElement.Focusable)
            {
                foreach (FrameworkElement element in groups[GetName(senderElement)])
                {
                    if (!ReferenceEquals(element, senderElement))
                    {
                        blurAnimation.Begin(element);
                    }
                }
            }
        }

        private static void Element_OutOfFocus(object sender, object e)
        {
            foreach (FrameworkElement element in groups[GetName((FrameworkElement)sender)])
            {
                if (!ReferenceEquals(element, sender))
                {
                    blurReverseAnimation.Begin(element);
                }
            }
        }
    }
}
