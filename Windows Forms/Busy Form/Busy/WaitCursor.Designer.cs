namespace Busy
{
    partial class WaitCursor
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.secondsToWaitSpinner = new System.Windows.Forms.NumericUpDown();
            this.waitButton = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.secondsToWaitSpinner)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.secondsToWaitSpinner);
            this.groupBox1.Controls.Add(this.waitButton);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(162, 51);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Waiting Cursor";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(106, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Seconds";
            // 
            // secondsToWaitSpinner
            // 
            this.secondsToWaitSpinner.Location = new System.Drawing.Point(50, 20);
            this.secondsToWaitSpinner.Name = "secondsToWaitSpinner";
            this.secondsToWaitSpinner.Size = new System.Drawing.Size(54, 20);
            this.secondsToWaitSpinner.TabIndex = 1;
            this.secondsToWaitSpinner.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            // 
            // waitButton
            // 
            this.waitButton.Location = new System.Drawing.Point(6, 19);
            this.waitButton.Name = "waitButton";
            this.waitButton.Size = new System.Drawing.Size(39, 23);
            this.waitButton.TabIndex = 0;
            this.waitButton.Text = "Wait";
            this.waitButton.UseVisualStyleBackColor = true;
            this.waitButton.Click += new System.EventHandler(this.waitButton_Click);
            // 
            // WaitCursor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox1);
            this.Name = "WaitCursor";
            this.Size = new System.Drawing.Size(162, 51);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.secondsToWaitSpinner)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown secondsToWaitSpinner;
        private System.Windows.Forms.Button waitButton;
    }
}
