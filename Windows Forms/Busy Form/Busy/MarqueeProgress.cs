using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Busy
{
    public partial class MarqueeProgress : UserControl
    {
        bool showProgress = false;

        public MarqueeProgress()
        {
            InitializeComponent();
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            marqueeProgressBar.Style = ProgressBarStyle.Marquee;
        }

        private void stopButton_Click(object sender, EventArgs e)
        {
            marqueeProgressBar.Style = ProgressBarStyle.Blocks;
        }

        private void progressButton_Click(object sender, EventArgs e)
        {
            marqueeProgressBar.Style = ProgressBarStyle.Marquee;

            int milliSecondsToWait = (int)secondsToWaitSpinner.Value * 1000;
            System.Threading.Thread.Sleep(milliSecondsToWait);

            marqueeProgressBar.Style = ProgressBarStyle.Blocks;
        }

        private void progressButton2_Click(object sender, EventArgs e)
        {
            showProgress = true;
            timer.Enabled = true;
            timer.Start();

            int milliSecondsToWait = (int)secondsToWaitSpinner2.Value * 1000;
            System.Threading.Thread.Sleep(milliSecondsToWait);

            showProgress = false;
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if (showProgress)
            {
                marqueeProgressBar.Style = ProgressBarStyle.Marquee;
            }
            else
            {
                marqueeProgressBar.Style = ProgressBarStyle.Blocks;
                timer.Stop();
                timer.Enabled = false;
            }            
        }

        private void progressButton3_Click(object sender, EventArgs e)
        {
            marqueeProgressBar.Style = ProgressBarStyle.Marquee;
            backgroundWorker.RunWorkerAsync();
        }

        private void backgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            int milliSecondsToWait = (int)secondsToWaitSpinner3.Value * 1000;
            System.Threading.Thread.Sleep(milliSecondsToWait);

            backgroundWorker.ReportProgress(100);
        }

        private void backgroundWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            marqueeProgressBar.Style = ProgressBarStyle.Blocks;
        }


    }
}
