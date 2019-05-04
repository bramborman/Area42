using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

namespace TAG
{
    public sealed class CharacterDesigner : ContentControl
    {
        private const double BORDER_SIZE = 0.5;

        public static readonly DependencyProperty CharWidthProperty = DependencyProperty.Register(nameof(CharWidth),
                                                                                                  typeof(uint),
                                                                                                  typeof(CharacterDesigner),
                                                                                                  new PropertyMetadata(CharWidthPropertyChanged));
        public static readonly DependencyProperty CharHeightProperty = DependencyProperty.Register(nameof(CharHeight),
                                                                                                   typeof(uint),
                                                                                                   typeof(CharacterDesigner),
                                                                                                   new PropertyMetadata(CharHeightPropertyChanged));
        public static readonly DependencyProperty BrushCharProperty = DependencyProperty.Register(nameof(BrushChar),
                                                                                                  typeof(string),
                                                                                                  typeof(CharacterDesigner),
                                                                                                  new PropertyMetadata(BrushCharPropertyChanged));
        public static readonly DependencyProperty CellBackgroundProperty = DependencyProperty.Register(nameof(CellBackground),
                                                                                                       typeof(Brush),
                                                                                                       typeof(CharacterDesigner));
        public static readonly DependencyProperty CellForegroundProperty = DependencyProperty.Register(nameof(CellForeground),
                                                                                                       typeof(Brush), typeof(CharacterDesigner));
        public static readonly DependencyProperty GenericCharCellBackgroundProperty = DependencyProperty.Register(nameof(GenericCharCellBackground),
                                                                                                                  typeof(Brush),
                                                                                                                  typeof(CharacterDesigner));

        private readonly LinkedList<StackPanel> unusedRowStorage = new LinkedList<StackPanel>();
        private readonly LinkedList<TextBlock> unusedCellStorage = new LinkedList<TextBlock>();
        private readonly StackPanel rows;

        private object mouseDownCell;
        private object mouseMoveStartCell;
        private bool brushCanBeUsed = false;
        private bool isGenericBrushChar = false;

        public uint CharWidth
        {
            get { return (uint)GetValue(CharWidthProperty); }
            set { SetValue(CharWidthProperty, value); }
        }
        public uint CharHeight
        {
            get { return (uint)GetValue(CharHeightProperty); }
            set { SetValue(CharHeightProperty, value); }
        }
        public string BrushChar
        {
            get { return (string)GetValue(BrushCharProperty); }
            set { SetValue(BrushCharProperty, value); }
        }
        public Brush CellBackground
        {
            get { return (Brush)GetValue(CellBackgroundProperty); }
            set { SetValue(CellBackgroundProperty, value); }
        }
        public Brush CellForeground
        {
            get { return (Brush)GetValue(CellForegroundProperty); }
            set { SetValue(CellForegroundProperty, value); }
        }
        public Brush GenericCharCellBackground
        {
            get { return (Brush)GetValue(GenericCharCellBackgroundProperty); }
            set { SetValue(GenericCharCellBackgroundProperty, value); }
        }

        public CharacterDesigner()
        {
            rows = new StackPanel()
            {
                Margin = new Thickness(BORDER_SIZE)
            };

            Border border = new Border()
            {
                DataContext = this,
                Child = rows
            };
            border.SetBinding(BackgroundProperty, nameof(Background));

            Content = border;
        }

        private static void CharWidthPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            CharacterDesigner designer = (CharacterDesigner)d;
            StackPanel rows = designer.rows;
            uint newValue = (uint)e.NewValue;

            if (newValue > (uint)e.OldValue)
            {
                foreach (StackPanel row in rows.Children)
                {
                    do
                    {
                        row.Children.Add(designer.GetNewCell());
                    }
                    while (row.Children.Count != newValue);
                }
            }
            else
            {
                int newValueInt = (int)newValue;

                foreach (StackPanel row in rows.Children)
                {
                    for (int column = row.Children.Count - 1; column > newValueInt - 1; column--)
                    {
                        TextBlock cell = (TextBlock)row.Children[column];
                        row.Children.RemoveAt(column);

                        designer.StoreUnusedCell(cell);
                    }
                }
            }
        }

        private static void CharHeightPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            CharacterDesigner designer = (CharacterDesigner)d;
            StackPanel rows = designer.rows;
            uint newValue = (uint)e.NewValue;

            if (rows.Children.Count < newValue)
            {
                do
                {
                    StackPanel row = designer.GetNewRow();

                    for (int i = 0; i < designer.CharWidth; i++)
                    {
                        row.Children.Add(designer.GetNewCell());
                    }

                    rows.Children.Add(row);
                }
                while (rows.Children.Count != newValue);
            }
            else
            {
                int newValueInt = (int)newValue;

                for (int row = rows.Children.Count - 1; row > newValueInt - 1; row--)
                {
                    StackPanel rowElement = (StackPanel)rows.Children[row];

                    for (int column = rowElement.Children.Count - 1; column >= 0; column--)
                    {
                        TextBlock cell = (TextBlock)rowElement.Children[column];
                        rowElement.Children.RemoveAt(column);

                        designer.StoreUnusedCell(cell);
                    }
                    
                    rows.Children.RemoveAt(row);
                    designer.StoreUnusedRow(rowElement);
                }
            }
        }

        private static void BrushCharPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            CharacterDesigner designer = (CharacterDesigner)d;
            string newValue = (string)e.NewValue;

            designer.isGenericBrushChar = string.Equals(newValue, FontCreator.GENERIC_TEXT);
            designer.brushCanBeUsed = designer.isGenericBrushChar || !string.IsNullOrWhiteSpace(newValue);
        }

        private StackPanel GetNewRow()
        {
            if (unusedRowStorage.Count != 0)
            {
                StackPanel stackPanel = unusedRowStorage.Last.Value;
                unusedRowStorage.RemoveLast();

                return stackPanel;
            }
            else
            {
                return new StackPanel()
                {
                    Orientation = Orientation.Horizontal
                };
            }
        }

        private void StoreUnusedRow(StackPanel row)
        {
            unusedRowStorage.AddLast(row);
        }

        private TextBlock GetNewCell()
        {
            TextBlock cell;

            if (unusedCellStorage.Count != 0)
            {
                cell = unusedCellStorage.Last.Value;
                unusedCellStorage.RemoveLast();
            }
            else
            {
                cell = new TextBlock()
                {
                    DataContext = this,
                    TextAlignment = TextAlignment.Center,
                    FontSize = 18.5d,
                    Width = 25d,
                    Height = 25d,
                    Margin = new Thickness(BORDER_SIZE)
                };
                cell.SetBinding(TextBlock.ForegroundProperty, nameof(CellForeground));

                cell.MouseMove += Cell_MouseMove;
                cell.MouseUp += Cell_MouseUp;
                cell.MouseDown += Cell_MouseDown;
            }

            // Set some default values
            ToggleCellContent(cell, true, true);
            return cell;
        }

        private void StoreUnusedCell(TextBlock cell)
        {
            unusedCellStorage.AddLast(cell);
        }

        private void ToggleCellContent(TextBlock cell, bool canRemove, bool forceRemove)
        {
            if (canRemove && (string.Equals(cell.Text, BrushChar) || cell.Background == GenericCharCellBackground))
            {
                forceRemove = true;
            }

            if (!forceRemove)
            {
                if (brushCanBeUsed)
                {
                    if (isGenericBrushChar)
                    {
                        cell.SetBinding(TextBlock.BackgroundProperty, nameof(GenericCharCellBackground));
                    }
                    else
                    {
                        cell.SetBinding(TextBlock.BackgroundProperty, nameof(CellBackground));
                        cell.Text = BrushChar;
                    }
                }
            }
            else
            {
                cell.SetBinding(TextBlock.BackgroundProperty, nameof(CellBackground));
                cell.Text = null;
            }
        }

        private void Cell_MouseMove(object sender, MouseEventArgs e)
        {
            TextBlock cell = (TextBlock)sender;

            if (e.LeftButton == MouseButtonState.Pressed)
            {
                ToggleCellContent(cell, false, false);
                mouseMoveStartCell = sender;
            }
            else if (e.RightButton == MouseButtonState.Pressed)
            {
                ToggleCellContent(cell, true, true);
                mouseMoveStartCell = sender;
            }
        }

        private void Cell_MouseUp(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
            {
                Focus();
            }

            if (mouseMoveStartCell == null && ReferenceEquals(mouseDownCell, sender) && e.ClickCount % 2 == 1)
            {
                TextBlock cell = (TextBlock)sender;

                if (e.ChangedButton == MouseButton.Left)
                {
                    ToggleCellContent(cell, true, false);
                }
                else if (e.ChangedButton == MouseButton.Right)
                {
                    ToggleCellContent(cell, true, true);
                }
            }

            mouseDownCell = null;
            mouseMoveStartCell = null;
        }

        private void Cell_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left || e.ChangedButton == MouseButton.Right)
            {
                mouseDownCell = sender;
            }
        }
    }
}
