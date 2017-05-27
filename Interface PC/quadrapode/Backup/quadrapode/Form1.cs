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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Under construction", "CELEC");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Under construction", "video");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Under construction", "Document");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Under construction", "Realisation");
        }

     
        private void button9_Click(object sender, EventArgs e)
        {
            Option myNewForm = new Option();

            myNewForm.Show();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Command_Manuel myNewForm = new Command_Manuel();

            myNewForm.Show();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Fonctionnement_AUTO myNewForm = new Fonctionnement_AUTO();

            myNewForm.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
           /* if (!serialPort1.IsOpen)
            {
                serialPort1.Open();
            }*/
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("1");
            }
            button5.Visible = false;
            button6.Visible = true;
        }
        
        private void button6_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                serialPort1.Write("0");
            }
            if (serialPort1.IsOpen)
            {
                serialPort1.Close();
            }
            button5.Visible = true;
            button6.Visible = false;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Robot_Dance myNewForm = new Robot_Dance();
            myNewForm.Show();
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Robot_Dance myNewForm = new Robot_Dance();
            myNewForm.Show();
        }

        
    }
}
