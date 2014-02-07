using System;
using System.IO.Ports;
using System.Windows;
using System.Windows.Threading;

namespace SerialComListener
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private SerialPort _port;


        public MainWindow()
        {
            InitializeComponent();
            _port = new SerialPort("COM3", 9600);
            _port.DataReceived += PortOnDataReceived;
        }

        private void PortOnDataReceived(object sender, SerialDataReceivedEventArgs serialDataReceivedEventArgs)
        {
            var message = _port.ReadExisting();

            ComMsg.Dispatcher.Invoke(
                DispatcherPriority.Normal,
                new Action(() => ComMsg.Items.Add(message))
                );

        }

        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            _port.Open();
        }


        private void MainWindow_OnClosed(object sender, EventArgs e)
        {
            _port.Close();
        }
    }
}
