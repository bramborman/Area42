using System;
using System.Globalization;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        private readonly string numberDecimalSeparator = NumberFormatInfo.CurrentInfo.NumberDecimalSeparator;

        private double? temp;
        private string operation;

        public Form1()
        {
            InitializeComponent();
            Bt_DecimalSeparator.Text = numberDecimalSeparator;
        }

        private void AddToOutput(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            string output = La_Output.Text;

            if (output == "0" && button.Text != ",")
            {
                output = button.Text;
            }
            else
            {
                output += button.Text;
            }

            double test;

            if (double.TryParse(output, out test))
            {
                La_Output.Text = output;
            }
        }
        
        private void Clear(object sender, EventArgs e)
        {
            La_Output.Text = "0";

            if (((Button)sender).Text == "C")
            {

            }
        }

        private void DoOperation(object sender, EventArgs e)
        {
            string operation = ((Button)sender).Text;

            try
            {
                double input = double.Parse(La_Output.Text);

                if (operation == "=")
                {
                    switch (this.operation)
                    {
                        case "+":

                            break;
                            
                        case "-":

                            break;

                        case "X":

                            break;

                        case "/":

                            break;
                    }
                }
                else
                {
                    this.operation = operation;
                    La_Output.Text = "0";
                }
            }
            catch (Exception exception)
            {
                MessageBox.Show("Něco se nepovedlo :(\n" + exception.Message);
            }
        }
    }
}
