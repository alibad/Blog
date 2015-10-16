namespace Busy
{
    partial class RealProgress
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
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.timeSpinner = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.stepsSpinner = new System.Windows.Forms.NumericUpDown();
            this.doButton = new System.Windows.Forms.Button();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.blocksProgressBar = new System.Windows.Forms.ToolStripProgressBar();
            this.backgroundWorker = new System.ComponentModel.BackgroundWorker();
            this.label1 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.timeSpinner2 = new System.Windows.Forms.NumericUpDown();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.stepsSpinner2 = new System.Windows.Forms.NumericUpDown();
            this.doButton2 = new System.Windows.Forms.Button();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.timeSpinner)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.stepsSpinner)).BeginInit();
            this.statusStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.timeSpinner2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.stepsSpinner2)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.timeSpinner2);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.label8);
            this.groupBox3.Controls.Add(this.stepsSpinner2);
            this.groupBox3.Controls.Add(this.doButton2);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.timeSpinner);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.stepsSpinner);
            this.groupBox3.Controls.Add(this.doButton);
            this.groupBox3.Controls.Add(this.statusStrip);
            this.groupBox3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox3.Location = new System.Drawing.Point(0, 0);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(233, 188);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Real Progress Bar";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(154, 68);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(69, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "milli-seconds.";
            // 
            // timeSpinner
            // 
            this.timeSpinner.Location = new System.Drawing.Point(94, 64);
            this.timeSpinner.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.timeSpinner.Name = "timeSpinner";
            this.timeSpinner.Size = new System.Drawing.Size(62, 20);
            this.timeSpinner.TabIndex = 5;
            this.timeSpinner.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 68);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Each step takes ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(103, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "steps.";
            // 
            // stepsSpinner
            // 
            this.stepsSpinner.Location = new System.Drawing.Point(52, 37);
            this.stepsSpinner.Name = "stepsSpinner";
            this.stepsSpinner.Size = new System.Drawing.Size(50, 20);
            this.stepsSpinner.TabIndex = 2;
            this.stepsSpinner.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // doButton
            // 
            this.doButton.Location = new System.Drawing.Point(7, 36);
            this.doButton.Name = "doButton";
            this.doButton.Size = new System.Drawing.Size(38, 23);
            this.doButton.TabIndex = 1;
            this.doButton.Text = "Do";
            this.doButton.UseVisualStyleBackColor = true;
            this.doButton.Click += new System.EventHandler(this.doButton_Click);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.blocksProgressBar});
            this.statusStrip.Location = new System.Drawing.Point(3, 163);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(227, 22);
            this.statusStrip.TabIndex = 0;
            this.statusStrip.Text = "statusStrip2";
            // 
            // blocksProgressBar
            // 
            this.blocksProgressBar.Name = "blocksProgressBar";
            this.blocksProgressBar.Size = new System.Drawing.Size(100, 16);
            // 
            // backgroundWorker
            // 
            this.backgroundWorker.WorkerReportsProgress = true;
            this.backgroundWorker.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker_DoWork);
            this.backgroundWorker.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.backgroundWorker_Completed);
            this.backgroundWorker.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.backgroundWorker_ProgressChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label1.Location = new System.Drawing.Point(4, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(179, 15);
            this.label1.TabIndex = 7;
            this.label1.Text = "Using Background Worker Process:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label5.Location = new System.Drawing.Point(7, 89);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(136, 15);
            this.label5.TabIndex = 8;
            this.label5.Text = "In between Code (works!): ";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(154, 140);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(69, 13);
            this.label6.TabIndex = 14;
            this.label6.Text = "milli-seconds.";
            // 
            // timeSpinner2
            // 
            this.timeSpinner2.Location = new System.Drawing.Point(94, 136);
            this.timeSpinner2.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.timeSpinner2.Name = "timeSpinner2";
            this.timeSpinner2.Size = new System.Drawing.Size(62, 20);
            this.timeSpinner2.TabIndex = 13;
            this.timeSpinner2.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(7, 140);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(87, 13);
            this.label7.TabIndex = 12;
            this.label7.Text = "Each step takes ";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(103, 113);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(35, 13);
            this.label8.TabIndex = 11;
            this.label8.Text = "steps.";
            // 
            // stepsSpinner2
            // 
            this.stepsSpinner2.Location = new System.Drawing.Point(52, 109);
            this.stepsSpinner2.Name = "stepsSpinner2";
            this.stepsSpinner2.Size = new System.Drawing.Size(50, 20);
            this.stepsSpinner2.TabIndex = 10;
            this.stepsSpinner2.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // doButton2
            // 
            this.doButton2.Location = new System.Drawing.Point(7, 108);
            this.doButton2.Name = "doButton2";
            this.doButton2.Size = new System.Drawing.Size(38, 23);
            this.doButton2.TabIndex = 9;
            this.doButton2.Text = "Do";
            this.doButton2.UseVisualStyleBackColor = true;
            this.doButton2.Click += new System.EventHandler(this.doButton2_Click);
            // 
            // RealProgress
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox3);
            this.Name = "RealProgress";
            this.Size = new System.Drawing.Size(233, 188);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.timeSpinner)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.stepsSpinner)).EndInit();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.timeSpinner2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.stepsSpinner2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown timeSpinner;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown stepsSpinner;
        private System.Windows.Forms.Button doButton;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripProgressBar blocksProgressBar;
        private System.ComponentModel.BackgroundWorker backgroundWorker;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown timeSpinner2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.NumericUpDown stepsSpinner2;
        private System.Windows.Forms.Button doButton2;
    }
}
