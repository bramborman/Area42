using System.Windows;
using System.Windows.Controls;

namespace TAG
{
    public sealed partial class ExtendedSlider : UserControl
    {
        public static readonly DependencyProperty LayoutProperty = DependencyProperty.Register(nameof(Layout),
                                                                                               typeof(ExtendedSliderLayout),
                                                                                               typeof(ExtendedSlider),
                                                                                               new PropertyMetadata(ExtendedSliderLayout.HorizontalLeft, LayoutPropertyChanged));
        public static readonly DependencyProperty ValueProperty = DependencyProperty.Register(nameof(Value), typeof(double), typeof(ExtendedSlider));
        public static readonly DependencyProperty MinimumProperty = DependencyProperty.Register(nameof(Minimum), typeof(double), typeof(ExtendedSlider));
        public static readonly DependencyProperty MaximumProperty = DependencyProperty.Register(nameof(Maximum), typeof(double), typeof(ExtendedSlider));
        
        public ExtendedSliderLayout Layout
        {
            get { return (ExtendedSliderLayout)GetValue(LayoutProperty); }
            set { SetValue(LayoutProperty, value); }
        }
        public double Value
        {
            get { return (double)GetValue(ValueProperty); }
            set { SetValue(ValueProperty, value); }
        }
        public double Minimum
        {
            get { return (double)GetValue(MinimumProperty); }
            set { SetValue(MinimumProperty, value); }
        }
        public double Maximum
        {
            get { return (double)GetValue(MaximumProperty); }
            set { SetValue(MaximumProperty, value); }
        }

        public ExtendedSlider()
        {
            InitializeComponent();
        }

        private static void LayoutPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            ExtendedSlider es = (ExtendedSlider)d;

            switch ((ExtendedSliderLayout)e.NewValue)
            {
                case ExtendedSliderLayout.HorizontalLeft:
                    Grid.SetRow(es.textBox, 1);
                    Grid.SetRow(es.slider, 1);
                    Grid.SetColumn(es.textBox, 0);
                    Grid.SetColumn(es.slider, 1);

                    es.slider.Orientation = Orientation.Horizontal;
                    es.slider.Margin = new Thickness(8d, 0d, 0d, 0d);
                    es.slider.HorizontalAlignment = HorizontalAlignment.Stretch;
                    es.slider.VerticalAlignment = VerticalAlignment.Center;
                    break;
                
                case ExtendedSliderLayout.HorizontalRight:
                    Grid.SetRow(es.textBox, 1);
                    Grid.SetRow(es.slider, 1);
                    Grid.SetColumn(es.textBox, 2);
                    Grid.SetColumn(es.slider, 1);

                    es.slider.Orientation = Orientation.Horizontal;
                    es.slider.Margin = new Thickness(0d, 0d, 8d, 0d);
                    es.slider.HorizontalAlignment = HorizontalAlignment.Stretch;
                    es.slider.VerticalAlignment = VerticalAlignment.Center;
                    break;

                case ExtendedSliderLayout.VerticalTop:
                    Grid.SetRow(es.textBox, 0);
                    Grid.SetRow(es.slider, 1);
                    Grid.SetColumn(es.textBox, 1);
                    Grid.SetColumn(es.slider, 1);

                    es.slider.Orientation = Orientation.Vertical;
                    es.slider.Margin = new Thickness(0d, 8d, 0d, 0d);
                    es.slider.HorizontalAlignment = HorizontalAlignment.Center;
                    es.slider.VerticalAlignment = VerticalAlignment.Stretch;
                    break;

                case ExtendedSliderLayout.VerticalBottom:
                    Grid.SetRow(es.textBox, 2);
                    Grid.SetRow(es.slider, 1);
                    Grid.SetColumn(es.textBox, 1);
                    Grid.SetColumn(es.slider, 1);

                    es.slider.Orientation = Orientation.Vertical;
                    es.slider.Margin = new Thickness(0d, 0d, 0d, 8d);
                    es.slider.HorizontalAlignment = HorizontalAlignment.Center;
                    es.slider.VerticalAlignment = VerticalAlignment.Stretch;
                    break;

            }
        }
    }
}
