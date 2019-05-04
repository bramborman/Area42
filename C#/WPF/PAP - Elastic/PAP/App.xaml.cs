using System.Windows;

namespace PAP
{
    public sealed partial class App : Application
    {
        protected override async void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
            await PAP.MainWindow.Instance.ShowAnimatedAsync();
        }
    }
}

/*
 * Blurred icon buttons
 * GoUp/Down Height jump
 * MenuToGameTransition - plane scale issue
 *                      - use just one plane down scaled
 *                      - background animation lag
 * costura - config + packagereference?
 * FocusVisualStyle
 * cleanup
 * Fly enter animation lag
 * maximized closing animation
 * first time the animation to AboutPage behaves weird
 * {StaticResource ButtonSize} in MainWindow
 * resources cleanup etc
 */
