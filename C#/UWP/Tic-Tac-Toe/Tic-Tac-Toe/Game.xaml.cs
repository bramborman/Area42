using System;
using Windows.UI;
using Windows.UI.Core;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

namespace TicTacToe
{
    public sealed partial class Game : Page
    {
        private const int CELL_BORDER       = 2;
        private const int CELL_BORDER_EDGE  = CELL_BORDER * 2;

        public static readonly DependencyProperty PlayerNumberProperty = DependencyProperty.Register(nameof(PlayerNumber), typeof(int), typeof(Game), null);

        private readonly SolidColorBrush defaultCellBackground  = new SolidColorBrush(Colors.Transparent);
        private readonly SolidColorBrush player1CellBrush       = new SolidColorBrush(Color.FromArgb(0xff, 0xb3, 0x11, 0x11));
        private readonly SolidColorBrush player2CellBrush       = new SolidColorBrush(Color.FromArgb(0xff, 0x11, 0x6b, 0xb3));

        private bool _player1;
        private int cellsToWin;
        private int gameBoardSize;
        private Button[,] cells;
        private DelegateCommand colorizeCell;
        private SolidColorBrush cellBorderBrush;

        private bool Player1
        {
            get { return _player1; }
            set
            {
                if (_player1 != value)
                {
                    _player1 = value;
                    PlayerNumber = _player1 ? 1 : 2;
                }
            }
        }
        private int PlayerNumber
        {
            get { return (int)GetValue(PlayerNumberProperty); }
            set { SetValue(PlayerNumberProperty, value); }
        }

        public Game()
        {
            Player1 = true;
            InitializeComponent();
        }

        private void Page_Loaded(object sender, RoutedEventArgs e)
        {
            cellBorderBrush = (SolidColorBrush)Resources["BorderBrush"];

            cells           = new Button[gameBoardSize, gameBoardSize];
            cellsToWin      = Math.Max(gameBoardSize - 2, 3);

            colorizeCell = new DelegateCommand(async (colorizeCellSender, colorizeCellE) =>
            {
                SolidColorBrush currentPlayerCellBrush = Player1 ? player1CellBrush : player2CellBrush;

                Button clickedCell      = (Button)colorizeCellE;
                clickedCell.Background  = currentPlayerCellBrush;
                clickedCell.IsEnabled   = false;

                bool win = false;

                for (int row = 0; row < gameBoardSize; row++)
                {
                    for (int column = 0; column < gameBoardSize; column++)
                    {
                        if (cells[row, column].Background == currentPlayerCellBrush)
                        {
                            bool goRight = column + cellsToWin <= gameBoardSize;
                            bool goDown  = row + cellsToWin <= gameBoardSize;

                            if (goRight || goDown)
                            {
                                bool goDownLeft     = goDown && column - (cellsToWin - 1) >= 0;
                                bool goDownRight    = goDown && goRight;

                                int rightCount      = 1;
                                int downCount       = 1;
                                int downLeftCount   = 1;
                                int downRightCount  = 1;

                                for (int i = 1; i < gameBoardSize; i++)
                                {
                                    if (goRight)
                                    {
                                        if (column + i < gameBoardSize && cells[row, column + i].Background == currentPlayerCellBrush)
                                        {
                                            if (++rightCount == cellsToWin)
                                            {
                                                win = true;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            rightCount = 0;
                                            goRight = false;
                                        }
                                    }

                                    if (goDown)
                                    {
                                        if (row + i < gameBoardSize && cells[row + i, column].Background == currentPlayerCellBrush)
                                        {
                                            if (++downCount == cellsToWin)
                                            {
                                                win = true;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            downCount = 0;
                                            goDown = false;
                                        }
                                    }

                                    if (goDownLeft)
                                    {
                                        if (row + i < gameBoardSize && column - i >= 0 && cells[row + i, column - i].Background == currentPlayerCellBrush)
                                        {
                                            if (++downLeftCount == cellsToWin)
                                            {
                                                win = true;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            downLeftCount = 0;
                                            goDownLeft = false;
                                        }
                                    }

                                    if (goDownRight)
                                    {
                                        if (row + i < gameBoardSize && column + i < gameBoardSize && cells[row + i, column + i].Background == currentPlayerCellBrush)
                                        {
                                            if (++downRightCount == cellsToWin)
                                            {
                                                win = true;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            downRightCount = 0;
                                            goDownRight = false;
                                        }
                                    }

                                    if (!goRight && !goDown && !goDownLeft && !goDownRight)
                                    {
                                        break;
                                    }
                                }
                            }
                        }

                        if (win)
                        {
                            break;
                        }
                    }

                    if (win)
                    {
                        break;
                    }
                }

                if (win)
                {
                    ContentDialog winDialog = new ContentDialog
                    {
                        Title = $"Player {PlayerNumber} won!",
                        SecondaryButtonText = "Back"
                    };

                    winDialog.SecondaryButtonClick += (winDialogSender, winDialogE) =>
                    {
                        Frame.GoBack();
                    };

                    foreach (Button cell in cells)
                    {
                        cell.IsEnabled = false;
                    }

                    await winDialog.ShowAsync();
                }

                Player1 = !Player1;
            });

            for (int row = 0; row < gameBoardSize; row++)
            {
                Gr_GameBoard.RowDefinitions.Add(new RowDefinition());

                for (int column = 0; column < gameBoardSize; column++)
                {
                    if (row == 0)
                    {
                        Gr_GameBoard.ColumnDefinitions.Add(new ColumnDefinition());
                    }

                    Button cell = new Button
                    {
                        Background          = defaultCellBackground,
                        HorizontalAlignment = HorizontalAlignment.Stretch,
                        VerticalAlignment   = VerticalAlignment.Stretch,
                        BorderBrush         = cellBorderBrush,
                        BorderThickness     = new Thickness(column  == 0                 ? CELL_BORDER_EDGE : CELL_BORDER,
                                                            row     == 0                 ? CELL_BORDER_EDGE : CELL_BORDER,
                                                            column  == gameBoardSize - 1 ? CELL_BORDER_EDGE : CELL_BORDER,
                                                            row     == gameBoardSize - 1 ? CELL_BORDER_EDGE : CELL_BORDER),
                        Style               = (Style)Resources["Cell"],
                        Command             = colorizeCell
                    };

                    cell.CommandParameter = cell;

                    Gr_GameBoard.Children.Add(cell);
                    Grid.SetRow(cell, row);
                    Grid.SetColumn(cell, column);

                    cells[row, column] = cell;
                }
            }
        }

        private void Game_BackRequested(object sender, BackRequestedEventArgs e)
        {
            e.Handled = true;
            Frame.GoBack();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            SystemNavigationManager systemNavigationManager     = SystemNavigationManager.GetForCurrentView();
            systemNavigationManager.AppViewBackButtonVisibility = AppViewBackButtonVisibility.Visible;
            systemNavigationManager.BackRequested               += Game_BackRequested;

            gameBoardSize = (int)e.Parameter;
        }

        protected override void OnNavigatingFrom(NavigatingCancelEventArgs e)
        {
            SystemNavigationManager systemNavigationManager     = SystemNavigationManager.GetForCurrentView();
            systemNavigationManager.AppViewBackButtonVisibility = AppViewBackButtonVisibility.Collapsed;
            systemNavigationManager.BackRequested               -= Game_BackRequested;
            
            base.OnNavigatingFrom(e);
        }
    }
}
