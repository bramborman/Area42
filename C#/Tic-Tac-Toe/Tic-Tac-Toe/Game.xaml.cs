using System;
using System.Collections.Generic;
using System.Linq;
using Windows.UI;
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

        private readonly SolidColorBrush cellBorderBrush        = new SolidColorBrush(Colors.White);
        private readonly SolidColorBrush defaultCellBackground  = new SolidColorBrush(Colors.Transparent);
        private readonly SolidColorBrush player1CellBrush       = new SolidColorBrush(Colors.Red);
        private readonly SolidColorBrush player2CellBrush       = new SolidColorBrush(Colors.Blue);

        private bool _player1;
        private int cellsToWin;
        private int gameBoardSize;
        private List<Button> cells;
        private DelegateCommand colorizeCell;

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
            Loaded += (loadedSender, loadedE) =>
            {
                cells = new List<Button>(gameBoardSize * gameBoardSize);
                cellsToWin = Math.Max(gameBoardSize - 2, 3);

                colorizeCell = new DelegateCommand(
                    async (sender, e) =>
                    {
                        SolidColorBrush currentPlayerCellBrush = Player1 ? player1CellBrush : player2CellBrush;

                        Button clickedCell = (Button)e;
                        clickedCell.Background = currentPlayerCellBrush;
                        clickedCell.IsEnabled  = false;

                        List<Button> currentPlayerCells = new List<Button>(cells.Where(b => b.Background == currentPlayerCellBrush).OrderBy(b => cells.IndexOf(b)));

                        if (currentPlayerCells.Count >= cellsToWin)
                        {
                            int? lastRowIndex    = null;
                            int? lastColumnIndex = null;
                            int rowCount         = 0;
                            int columnCount      = 0;

                            foreach (Button cell in currentPlayerCells)
                            {
                                int currentIndex = cells.IndexOf(cell);

                                if (lastRowIndex == null || lastRowIndex == currentIndex - 1)
                                {
                                    lastRowIndex = currentIndex;
                                    rowCount++;
                                }
                                else
                                {
                                    lastRowIndex = null;
                                    rowCount     = 0;
                                }

                                if (lastColumnIndex == null || lastColumnIndex == currentIndex - gameBoardSize)
                                {
                                    lastColumnIndex = currentIndex;
                                    columnCount++;
                                }
                                else
                                {
                                    lastColumnIndex = null;
                                    columnCount     = 0;
                                }

                                if (rowCount == cellsToWin || columnCount == cellsToWin)
                                {
                                    ContentDialog winDialog = new ContentDialog
                                    {
                                        Title               = $"Player {PlayerNumber} won!",
                                        SecondaryButtonText = "Back"
                                    };

                                    winDialog.SecondaryButtonClick += (winDialogSender, winDialogE) =>
                                    {
                                        Frame.GoBack();
                                    };

                                    await winDialog.ShowAsync();

                                    break;
                                }
                            }
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
                            Style               = (Style)App.Current.Resources["Cell"],
                            Command             = colorizeCell
                        };

                        cell.CommandParameter = cell;

                        Gr_GameBoard.Children.Add(cell);
                        Grid.SetRow(cell, row);
                        Grid.SetColumn(cell, column);

                        cells.Add(cell);
                    }
                }
            };

            Player1 = true;
            InitializeComponent();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            gameBoardSize = (int)e.Parameter;
        }
    }
}
