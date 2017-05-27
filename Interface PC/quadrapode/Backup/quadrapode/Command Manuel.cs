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
                MessageBox.Show("chof lcabl de l conexion", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("2"); //up==2
            }
           
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("chof lcabl de l conexion", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("3");//down==3
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("chof lcabl de l conexion", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("4");//left==4
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("chof lcabl de l conexion", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("5");//right==5
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("chof lcabl de l conexion", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("6");
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("chof lcabl de l conexion", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("7");
            }
        }

        private void Command_Manuel_Load(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {
    if (!serialPort1.IsOpen)
            {
                MessageBox.Show("chof lcabl de l conexion", "Conexion");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("7");
            }
        }
        }
    }
}
