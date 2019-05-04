using System;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace PAP
{
    public abstract class Page : ContentControl
    {
        public static readonly DependencyProperty RequestedSizeProperty = DependencyProperty.Register(nameof(RequestedSize), typeof(Size), typeof(Page), new FrameworkPropertyMetadata(new Size(double.NaN, double.NaN)));

        public Size RequestedSize
        {
            get { return (Size)GetValue(RequestedSizeProperty); }
            set { SetValue(RequestedSizeProperty, value); }
        }
        public Frame Frame { get; set; }

        public Page()
        {

        }

        public virtual void OnNavigatingTo(bool animate, Type previousPageType)
        {
            if (animate)
            {
                Opacity = 0d;
            }
        }

        public virtual Task OnNavigatedToAsync(bool animate, Type previousPageType)
        {
            return animate ? Helpers.RunStoryboardAsync("OpacityShowingAnimation", this) : Task.CompletedTask;
        }

        public virtual Task OnNavigatingFromAsync(bool animate, Type nextPageType)
        {
            return animate ? Helpers.RunStoryboardAsync("OpacityHidingAnimation", this) : Task.CompletedTask;
        }

        public virtual void OnNavigatedFrom(bool animate, Type nextPageType)
        {

        }

        public virtual Task<bool> CanCloseAsync()
        {
            return Task.FromResult(true);
        }
    }
}
