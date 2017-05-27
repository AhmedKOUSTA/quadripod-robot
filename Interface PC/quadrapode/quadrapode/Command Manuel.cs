using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace quadrapode
{
    public partial class Command_Manuel : Form
    {
        public Command_Manuel()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("9"); //forward==9
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("A");//back==A
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("6");//left==6
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("7");//right==7
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("B");  //turn left
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("C");  //turn right
            }
        }

        private void Command_Manuel_Load(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("1");   //stand up
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("4");  //stop==stand fast
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("2");   //set down
            }
        }

        private void button10_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("4"); // get up fast
            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("you are not connected", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("5");  // set down fast
            }
        }

        private void button12_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serialPort1.Open();
                button12.Visible = false;
                button13.Visible = true;
            }
        }

        private void button13_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                serialPort1.Close();
                button12.Visible = true;
                button13.Visible = false;
            }
        }

    }
}

