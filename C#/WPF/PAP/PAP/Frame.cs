using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace PAP
{
    public sealed class Frame : ContentControl
    {
        public static readonly DependencyProperty CanGoBackProperty = DependencyProperty.Register(nameof(CanGoBack), typeof(bool), typeof(Frame), new FrameworkPropertyMetadata(false));
        public static readonly DependencyProperty CanGoForwardProperty = DependencyProperty.Register(nameof(CanGoForward), typeof(bool), typeof(Frame), new FrameworkPropertyMetadata(false));

        public Stack<Page> BackHistory { get; } = new Stack<Page>();
        public Stack<Page> ForwardHistory { get; } = new Stack<Page>();
        public bool CanGoBack
        {
            get { return (bool)GetValue(CanGoBackProperty); }
            set { SetValue(CanGoBackProperty, value); }
        }
        public bool CanGoForward
        {
            get { return (bool)GetValue(CanGoForwardProperty); }
            set { SetValue(CanGoForwardProperty, value); }
        }

        static Frame()
        {
            HorizontalContentAlignmentProperty.OverrideMetadata(typeof(Frame), new FrameworkPropertyMetadata(HorizontalAlignment.Stretch));
            VerticalContentAlignmentProperty.OverrideMetadata(typeof(Frame), new FrameworkPropertyMetadata(VerticalAlignment.Stretch));
        }

        public Task NavigateAsync(Page page)
        {
            return NavigateAsync(page, true);
        }

        public async Task NavigateAsync(Page page, bool animate)
        {
            Page previousPage = (Page)Content;
            Type previousPageType = previousPage?.GetType();
            Type pageType = page.GetType();

            if (previousPage != null)
            {
                BackHistory.Push(previousPage);
                await previousPage.OnNavigatingFromAsync(animate, pageType);
            }

            await MainWindow.Instance.ResizeAsync(page.RequestedSize);

            page.OnNavigatingTo(animate, previousPageType);
            Content = page;

            previousPage?.OnNavigatedFrom(animate, pageType);
            await page.OnNavigatedToAsync(animate, previousPageType);
        }

        public Task GoBackAsync()
        {
            Page page = BackHistory.Pop();
            ForwardHistory.Push(page);
            return NavigateAsync(page);
        }

        public Task GoForwardAsync()
        {
            Page page = ForwardHistory.Pop();
            BackHistory.Push(page);
            return NavigateAsync(page);
        }

        protected override void OnContentChanged(object oldContent, object newContent)
        {
            base.OnContentChanged(oldContent, newContent);

            if (oldContent is Page oldPage && ReferenceEquals(oldPage.Frame, this))
            {
                oldPage.Frame = null;
            }

            Page newPage = (Page)newContent;
            newPage.Frame = this;
            newPage.Focus();
        }

        public Task<bool> CanCloseAsync()
        {
            return ((Page)Content).CanCloseAsync();
        }
    }
}
