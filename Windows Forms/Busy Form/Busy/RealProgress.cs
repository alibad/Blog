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
    public partial class RealProgress : UserControl
    {
        public RealProgress()
        {
            InitializeComponent();
        }

        private void doButton_Click(object sender, EventArgs e)
        {
            backgroundWorker.RunWorkerAsync();
        }

        private void backgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            int totalWork = (int)stepsSpinner.Value;

            for (int i = 1; i <= totalWork; i++)
            {
                int milliSecondsToWait = (int)timeSpinner.Value;
                System.Threading.Thread.Sleep(milliSecondsToWait);

                int progress = i * 100 / totalWork;
                backgroundWorker.ReportProgress(progress);
            }
        }

        private void backgroundWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            blocksProgressBar.Value = e.ProgressPercentage;
        }

        private void backgroundWorker_Completed(object sender, RunWorkerCompletedEventArgs e)
        {
            blocksProgressBar.Value = 0;
        }

        private void doButton2_Click(object sender, EventArgs e)
        {
            int totalWork = (int)stepsSpinner2.Value;

            for (int i = 1; i <= totalWork; i++)
            {
                int milliSecondsToWait = (int)timeSpinner2.Value;
                System.Threading.Thread.Sleep(milliSecondsToWait);

                int progress = i * 100 / totalWork;
                blocksProgressBar.Value = progress;
            }

            blocksProgressBar.Value = 0;
        }
    }
}
