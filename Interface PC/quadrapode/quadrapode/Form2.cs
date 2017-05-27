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
    public partial class Form2 : Form
    {
        int max;
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serialPort1.Open();
            }
            if (serialPort1.IsOpen)
            {

                serialPort1.Write("8");  // gangnam style
               
                timer1.Enabled = true;
                button1.Visible = false;
                max = 30;
                progressBar1.Minimum = 0;
                progressBar1.Maximum = max;
                progressBar1.Step = 1;
            }
        }


        private void timer1_Tick_1(object sender, EventArgs e)
        {

            progressBar1.PerformStep();
            if (progressBar1.Value == max)
            {
                progressBar1.Value = 0;
                button1.Visible = true;
                timer1.Enabled = false;
            }
        }

    
    }
}

      
        
