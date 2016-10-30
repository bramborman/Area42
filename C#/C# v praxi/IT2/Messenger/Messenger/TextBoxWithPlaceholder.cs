using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Messenger
{
    public class TextBoxWithPlaceholder : TextBox
    {
        private Brush foregroundBackup;

        public static readonly DependencyProperty PlaceholderProperty           = DependencyProperty.Register(nameof(Placeholder), typeof(string), typeof(TextBoxWithPlaceholder));
        public static readonly DependencyProperty PlaceholderForegroundProperty = DependencyProperty.Register(nameof(PlaceholderForeground), typeof(Brush), typeof(TextBoxWithPlaceholder), new PropertyMetadata(new SolidColorBrush(Colors.LightGray)));

        public string Placeholder
        {
            get { return (string)GetValue(PlaceholderProperty); }
            set { SetValue(PlaceholderProperty, value); }
        }
        public Brush PlaceholderForeground
        {
            get { return (Brush)GetValue(PlaceholderForegroundProperty); }
            set { SetValue(PlaceholderForegroundProperty, value); }
        }

        public TextBoxWithPlaceholder()
        {
            Loaded += delegate
            {
                SetPlaceholder();
            };
        }

        private void SetPlaceholder()
        {
            if (IsFocused)
            {
                if (Text == Placeholder)
                {
                    Text = "";
                    Foreground = foregroundBackup;
                }
            }
            else
            {

                if (Text == "")
                {
                    Text = Placeholder;
                    foregroundBackup = Foreground;
                    Foreground = PlaceholderForeground;
                }
            }
        }

        protected override void OnGotFocus(RoutedEventArgs e)
        {
            SetPlaceholder();
            base.OnGotFocus(e);
        }

        protected override void OnLostFocus(RoutedEventArgs e)
        {
            SetPlaceholder();
            base.OnLostFocus(e);
        }
    }
}