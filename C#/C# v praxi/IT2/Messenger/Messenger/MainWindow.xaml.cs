using System;
using System.ComponentModel;
using System.Linq;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace Messenger
{
    public partial class MainWindow : Window
    {
        const int PORT_MIN = 10000;
        const string RECEIVING_STOP = "e48c22d52f449c8b83fff4a3c24bb320c9d24daa2ee298744c686dff6d4d55e8";
        const string PLACEHOLDER_IP = "Partner's IP";
        const string PLACEHOLDER_PORT = "Partner's port";

        static readonly int MaxMessageLength = (int)Application.Current.Resources["MaxMessageLength"] * 2;

        static int local_port = 57837;
        static string receivedMessage = "";
        static readonly DispatcherTimer receivingTimer = new DispatcherTimer() { Interval = TimeSpan.FromMilliseconds(10) };
        static Thread receivingThread;

        bool chatting = false;
        bool changingPort = false;
        int currentMessageRow = 0;
        int unreadedMessagesCount = 0;
        int partner_port = 0;
        IPAddress partner_IP = null;
        IPAddress local_IP = null;

        public MainWindow()
        {
            InitializeComponent();

            receivingTimer.Tick += ShowReceivedMessages;

            TX_NewMessage.MaxLength = MaxMessageLength / 2;

            foreach (NetworkInterface ni in NetworkInterface.GetAllNetworkInterfaces())
            {
                if (ni.GetIPProperties().GatewayAddresses.FirstOrDefault() != null)
                {
                    if (ni.NetworkInterfaceType == NetworkInterfaceType.Wireless80211 || ni.NetworkInterfaceType == NetworkInterfaceType.Ethernet)
                    {
                        if (ni.Name != "Hamachi")
                        {
                            foreach (UnicastIPAddressInformation ip in ni.GetIPProperties().UnicastAddresses)
                            {
                                if (ip.Address.AddressFamily == AddressFamily.InterNetwork)
                                {
                                    local_IP = ip.Address;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            TB_LocalInfo.Text = local_IP.ToString() + ":" + local_port;
        }

        private void Send(object sender, RoutedEventArgs e)
        {
            if (TX_NewMessage.Text != "")
            {
                SendMessage(TX_NewMessage.Text, partner_IP, partner_port);
                AddMessage(TX_NewMessage.Text, true);

                TX_NewMessage.Text = "";
            }

            TX_NewMessage.Focus();
        }

        private void SendMessage(string message, IPAddress ip, int port)
        {
            // Client part
            Socket Server = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            Server.SendTo(Encoding.Unicode.GetBytes(message), new IPEndPoint(ip, port));
        }

        private static void ReceiveMessage()
        {
            // Server part
            Socket WinSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

            try
            {
                EndPoint Remote = new IPEndPoint(IPAddress.Any, local_port);
                WinSocket.Bind(Remote);

                byte[] data = new byte[MaxMessageLength];

                while (true)
                {
                    int received = WinSocket.ReceiveFrom(data, ref Remote);

                    if (Encoding.Unicode.GetString(data, 0, received) == RECEIVING_STOP)
                    {
                        break;
                    }

                    receivedMessage += Encoding.Unicode.GetString(data, 0, received);
                }
            }
            catch
            {
                MessageBox.Show("Cannot connect. You will not receive messages.\nPlease restart messenger and if this error continues try another local port.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }

            receivedMessage = "";

            WinSocket.Close();
            receivingTimer.Stop();
            receivingThread.Abort();
        }

        private void AddMessage(string message, bool sent)
        {
            const int MARGIN = 2;

            Grid MessageBlock = new Grid();
            MessageBlock.Margin = new Thickness(0, MARGIN, 0, 0);

            TextBlock Message = new TextBlock();
            Message.Text = message;
            Message.HorizontalAlignment = HorizontalAlignment.Center;
            Message.TextWrapping = TextWrapping.Wrap;
            Message.Margin = new Thickness(5);

            if (sent)
            {
                Message.Foreground = new SolidColorBrush(Colors.White);

                MessageBlock.Background = new SolidColorBrush(Color.FromRgb(24, 152, 255));
                MessageBlock.HorizontalAlignment = HorizontalAlignment.Right;

                Grid.SetColumn(MessageBlock, 2);
                Grid.SetColumnSpan(MessageBlock, 3);
            }
            else
            {
                Message.Foreground = new SolidColorBrush(Colors.Black);

                MessageBlock.Background = new SolidColorBrush(Colors.LightGray);
                MessageBlock.HorizontalAlignment = HorizontalAlignment.Left;

                Grid.SetColumn(MessageBlock, 1);
                Grid.SetColumnSpan(MessageBlock, 3);
            }

            MessageBlock.Children.Add(Message);

            Gr_Messages.RowDefinitions.Add(new RowDefinition() { Height = GridLength.Auto });
            Grid.SetRow(MessageBlock, currentMessageRow);

            Gr_Messages.Children.Add(MessageBlock);

            MessageBlock.Loaded += delegate
            {
                Polygon Triangle = new Polygon();
                PointCollection TrianglePoints = new PointCollection();

                if (sent)
                {
                    TrianglePoints.Add(new Point(0, 0));
                    TrianglePoints.Add(new Point(5, MessageBlock.ActualHeight / 2));
                    TrianglePoints.Add(new Point(0, MessageBlock.ActualHeight));
                    Triangle.HorizontalAlignment = HorizontalAlignment.Left;

                    Grid.SetColumn(Triangle, 5);
                }
                else
                {
                    TrianglePoints.Add(new Point(5, 0));
                    TrianglePoints.Add(new Point(0, MessageBlock.ActualHeight / 2));
                    TrianglePoints.Add(new Point(5, MessageBlock.ActualHeight));
                    Triangle.HorizontalAlignment = HorizontalAlignment.Right;

                    Grid.SetColumn(Triangle, 0);
                }

                Grid.SetRow(Triangle, currentMessageRow);
                Triangle.Fill = MessageBlock.Background;
                Triangle.Points = TrianglePoints;
                Triangle.Margin = new Thickness(0, MARGIN, 0, 0);

                Gr_Messages.Children.Add(Triangle);

                currentMessageRow++;
            };
        }

        private void ShowReceivedMessages(object sender, EventArgs e)
        {
            if (receivedMessage != "")
            {
                AddMessage(receivedMessage, false);
                receivedMessage = "";

                if (!IsActive)
                {
                    Console.Beep(4000, 100);
                    unreadedMessagesCount++;

                    Title = unreadedMessagesCount.ToString() + (unreadedMessagesCount == 1 ? " new message - Messenger" : " new messages - Messenger");
                }
            }
        }

        private void TX_NewMessage_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                Send(sender, null);
            }
        }

        private void Connect(object sender, RoutedEventArgs e)
        {
            if (changingPort)
            {
                // Check port
                if (!int.TryParse(TX_PortInput.Text, out local_port) || local_port <= PORT_MIN)
                {
                    local_port = 0;
                    MessageBox.Show("Not a valid port!\nMust be greater than " + PORT_MIN.ToString() + ".", "Error", MessageBoxButton.OK, MessageBoxImage.Error);

                    return;
                }

                TB_LocalInfo.Text = local_IP.ToString() + ":" + local_port;
                LocalPortSettings(sender, e);
            }
            else
            {
                // Check IP
                if (TX_IpInput.Text.ToLower() == "localhost")
                {
                    partner_IP = local_IP;

                    if (TX_PortInput.Text == PLACEHOLDER_PORT)
                    {
                        TX_PortInput.Text = local_port.ToString();
                        TX_IpInput.Foreground = new SolidColorBrush(Colors.Black);
                    }
                }
                else if (!IPAddress.TryParse(TX_IpInput.Text, out partner_IP))
                {
                    partner_IP = null;
                    MessageBox.Show("Not a valid IP address!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);

                    return;
                }

                // Check port
                if (!int.TryParse(TX_PortInput.Text, out partner_port) || partner_port <= PORT_MIN)
                {
                    partner_port = 0;
                    MessageBox.Show("Not a valid port!\nMust be greater than " + PORT_MIN.ToString() + ".", "Error", MessageBoxButton.OK, MessageBoxImage.Error);

                    return;
                }

                SwitchChat();
            }
        }

        private void Disconnect(object sender, CancelEventArgs e)
        {
            SendMessage(RECEIVING_STOP, local_IP, local_port);
        }

        private void SwitchChat()
        {
            if (!chatting)
            {
                chatting = true;

                receivingThread = new Thread(ReceiveMessage);
                receivingThread.Name = "Messenger background proccess";

                receivingThread.Start();
                receivingTimer.Start();

                Gr_Menu.Visibility = Visibility.Collapsed;
                Bt_PortSettings.Visibility = Visibility.Collapsed;

                TB_PartnerInfo.Visibility = Visibility.Visible;
                Gr_Chat.Visibility = Visibility.Visible;
                Bt_Back.Visibility = Visibility.Visible;

                TB_PartnerInfo.Text = partner_IP.ToString() + ":" + partner_port.ToString();
                TX_NewMessage.Focus();
            }
            else
            {
                chatting = false;

                Disconnect(null, null);
                Gr_Messages.Children.Clear();

                Gr_Menu.Visibility = Visibility.Visible;
                Bt_PortSettings.Visibility = Visibility.Visible;

                TB_PartnerInfo.Visibility = Visibility.Collapsed;
                Gr_Chat.Visibility = Visibility.Collapsed;
                Bt_Back.Visibility = Visibility.Collapsed;

                TX_IpInput.Text = PLACEHOLDER_IP;
                TX_PortInput.Text = PLACEHOLDER_PORT;

                TX_IpInput.Foreground = new SolidColorBrush(Colors.LightGray);
                TX_PortInput.Foreground = new SolidColorBrush(Colors.LightGray);

                Focus();
            }
        }

        private void LocalPortSettings(object sender, RoutedEventArgs e)
        {
            if (!changingPort)
            {
                changingPort = true;

                TX_IpInput.Visibility = Visibility.Collapsed;
                Bt_PortSettings.Visibility = Visibility.Collapsed;

                Bt_Back.Visibility = Visibility.Visible;

                TX_PortInput.Text = local_port.ToString();
                TX_PortInput.Foreground = new SolidColorBrush(Colors.Black);

                Bt_Connect.Content = "Change port";
            }
            else
            {
                changingPort = false;

                TX_IpInput.Visibility = Visibility.Visible;
                Bt_PortSettings.Visibility = Visibility.Visible;

                Bt_Back.Visibility = Visibility.Collapsed;

                if (!TX_PortInput.IsFocused)
                {
                    TX_PortInput.Text = PLACEHOLDER_PORT;
                    TX_PortInput.Foreground = new SolidColorBrush(Colors.LightGray);
                }
                else
                {
                    TX_PortInput.Text = "";
                }

                Bt_Connect.Content = "Connect";
            }
        }

        private void InputKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                Connect(sender, null);
            }
        }

        private void GoBack(object sender, RoutedEventArgs e)
        {
            if (changingPort)
            {
                LocalPortSettings(sender, null);
            }
            else if (chatting)
            {
                MessageBoxResult result = MessageBox.Show("Do you really want to quit connection with partner?\nYour conversation will be lost!", "Disconnecting", MessageBoxButton.YesNo, MessageBoxImage.Warning);

                if (result == MessageBoxResult.Yes)
                {
                    SwitchChat();
                }
            }
        }

        private void Title_Click(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
            {
                if (e.ClickCount == 2)
                {
                    Maximize(sender, null);
                }
                else
                {
                    DragMove();
                }
            }
        }

        private void MessengerWindow_Activated(object sender, EventArgs e)
        {
            unreadedMessagesCount = 0;
            Title = "Messenger";

            BorderBrush = new SolidColorBrush(Color.FromRgb(0x11, 0x6B, 0xB3));
            TB_Title.Foreground = new SolidColorBrush(Colors.White);

            Bt_Minimize.Foreground = new SolidColorBrush(Colors.White);
            Bt_Maximize.Foreground = new SolidColorBrush(Colors.White);
            Bt_Exit.Foreground = new SolidColorBrush(Colors.White);
        }

        private void MessengerWindow_Deactivated(object sender, EventArgs e)
        {
            BorderBrush = new SolidColorBrush(Color.FromRgb(0x33, 0x33, 0x33));
            TB_Title.Foreground = new SolidColorBrush(Colors.Gray);

            Bt_Minimize.Foreground = new SolidColorBrush(Colors.Gray);
            Bt_Maximize.Foreground = new SolidColorBrush(Colors.Gray);
            Bt_Exit.Foreground = new SolidColorBrush(Colors.Gray);
        }

        private void MessengerWindow_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Escape)
            {
                GoBack(sender, null);
            }
        }

        private void MessengerWindow_StateChanged(object sender, EventArgs e)
        {
            if (WindowState == WindowState.Normal)
            {
                Bt_Maximize.Content = "\xE922";
                BorderThickness = new Thickness(1);
            }
            else if (WindowState == WindowState.Maximized)
            {
                Bt_Maximize.Content = "\xE923";
                BorderThickness = new Thickness(0);
            }
        }

        private void Minimize(object sender, RoutedEventArgs e)
        {
            WindowState = WindowState.Minimized;
        }

        private void Maximize(object sender, RoutedEventArgs e)
        {
            WindowState = WindowState == WindowState.Normal ? WindowState.Maximized : WindowState.Normal;
        }

        private void Close(object sender, RoutedEventArgs e)
        {
            if (chatting)
            {
                MessageBoxResult result = MessageBox.Show("Do you really want to quit connection with partner?\nYour conversation will be lost!", "Disconnecting", MessageBoxButton.YesNo, MessageBoxImage.Warning);

                if (result == MessageBoxResult.Yes)
                {
                    Application.Current.Shutdown();
                }
            }

            Application.Current.Shutdown();
        }
    }
}