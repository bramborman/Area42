using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Grafika
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Brush randomColor = Brushes.Green;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Graf(object sender, RoutedEventArgs e)
        {
            double a, b, c, D, x1 = 0, x2 = 0;

            try
            {
                if (tx_a.Text == "")
                {
                    tx_a.Text = "0";
                }

                if (tx_b.Text == "")
                {
                    tx_b.Text = "0";
                }

                if (tx_c.Text == "")
                {
                    tx_c.Text = "0";
                }

                a = Convert.ToDouble(tx_a.Text);
                b = Convert.ToDouble(tx_b.Text);
                c = Convert.ToDouble(tx_c.Text);

                D = b * b - 4 * a * c;

                if (D > 0)
                {
                    x1 = (-b + Math.Sqrt(D)) / 2 * a;
                    x2 = (-b - Math.Sqrt(D)) / 2 * a;

                    lb_result.Content = "x1=" + x1 + "\nx2=" + x2;
                }
                else if (D == 0)
                {
                    x1 = -(b / 2 * a);

                    lb_result.Content = "x=" + x1;
                }
                else
                {
                    lb_result.Content = "Has no result!";
                }

                int width, height;
                double y = 0;

                for (int x = 0; x < 26;)
                {
                    width = (int)cv_paint.ActualWidth;
                    height = (int)cv_paint.ActualHeight;
                    
                    Line newLine = new Line();

                    newLine.HorizontalAlignment = HorizontalAlignment.Center;
                    newLine.VerticalAlignment = VerticalAlignment.Center;
                    newLine.StrokeThickness = 3;
                    newLine.Stroke = randomColor;
                    
                    newLine.X1 = (width / 2) + x;
                    newLine.Y1 = (height / 2) - y;

                    x++;
                    y = a * x * x + b * x + c;

                    newLine.X2 = (width / 2) + x;
                    newLine.Y2 = (height / 2) - y;

                    cv_paint.Children.Add(newLine);
                }

                y = 0;

                for (int x = 0; x > -26;)
                {
                    width = (int)cv_paint.ActualWidth;
                    height = (int)cv_paint.ActualHeight;

                    Line newLine = new Line();

                    newLine.HorizontalAlignment = HorizontalAlignment.Center;
                    newLine.VerticalAlignment = VerticalAlignment.Center;
                    newLine.StrokeThickness = 3;
                    newLine.Stroke = randomColor;

                    newLine.X1 = (width / 2) + x;
                    newLine.Y1 = (height / 2) - y;

                    x--;
                    y = a * x * x + b * x + c;

                    newLine.X2 = (width / 2) + x;
                    newLine.Y2 = (height / 2) - y;

                    cv_paint.Children.Add(newLine);
                }
            }
            catch
            {
                MessageBox.Show(string.Format("Wrong input is entered!"), "Wrong input!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        private void X2(object sender, RoutedEventArgs e)
        {
            int temp;

            Point last = new Point();
            last.X = 0;
            last.Y = 0;

            for (int x = 1; x < 26; x++)
            {
                temp = (int)cv_paint.ActualHeight;

                Line newLine = new Line();

                newLine.X1 = last.X;
                newLine.Y1 = temp - last.Y;

                last.X = x;
                last.Y = x * x;
                newLine.X2 = last.X;
                newLine.Y2 = temp - last.Y;

                newLine.HorizontalAlignment = HorizontalAlignment.Center;
                newLine.VerticalAlignment = VerticalAlignment.Center;

                newLine.StrokeThickness = 3;
                newLine.Stroke = randomColor;

                cv_paint.Children.Add(newLine);
            }

            /*for(int x = 0; x < 20; x++)
            {
                Ellipse newEllipse1 = new Ellipse();
                newEllipse1.Fill = randomColor;
                newEllipse1.Width = 3;
                newEllipse1.Height = 3;

                Canvas.SetBottom(newEllipse1, x * x);
                Canvas.SetLeft(newEllipse1, x + paintCanvas.Width / 2);

                cv_paint.Children.Add(newEllipse1);
            }*/
        }

        private void Vykresli(object sender, RoutedEventArgs e)
        {
            Ellipse newEllipse1 = new Ellipse();
            newEllipse1.Fill = randomColor;
            newEllipse1.Width = 50;
            newEllipse1.Height = 50;

            Canvas.SetTop(newEllipse1, 80);
            Canvas.SetLeft(newEllipse1, 70);

            cv_paint.Children.Add(newEllipse1);

            Line newLine = new Line();
            newLine.X1 = 50;
            newLine.Y1 = 50;
            newLine.X2 = 90;
            newLine.Y2 = 90;

            newLine.HorizontalAlignment = HorizontalAlignment.Left;
            newLine.VerticalAlignment = VerticalAlignment.Center;

            newLine.StrokeThickness = 5;
            newLine.Stroke = System.Windows.Media.Brushes.LightSteelBlue;

            cv_paint.Children.Add(newLine);
        }
    }
}
