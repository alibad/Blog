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
    public partial class WaitCursor : UserControl
    {
        public WaitCursor()
        {
            InitializeComponent();
        }

        private void waitButton_Click(object sender, EventArgs e)
        {
            Cursor.Current = Cursors.WaitCursor;

            int milliSecondsToWait = (int)secondsToWaitSpinner.Value * 1000;
            System.Threading.Thread.Sleep(milliSecondsToWait);

            Cursor.Current = Cursors.Default;
        }
    }
}
