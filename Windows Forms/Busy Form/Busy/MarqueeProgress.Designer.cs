namespace Busy
{
    partial class MarqueeProgress
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
            this.components = new System.ComponentModel.Container();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.stopButton = new System.Windows.Forms.Button();
            this.startButton = new System.Windows.Forms.Button();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.marqueeProgressBar = new System.Windows.Forms.ToolStripProgressBar();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.progressButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.secondsToWaitSpinner = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.secondsToWaitSpinner2 = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.progressButton2 = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.secondsToWaitSpinner3 = new System.Windows.Forms.NumericUpDown();
            this.label11 = new System.Windows.Forms.Label();
            this.progressButton3 = new System.Windows.Forms.Button();
            this.backgroundWorker = new System.ComponentModel.BackgroundWorker();
            this.groupBox2.SuspendLayout();
            this.statusStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.secondsToWaitSpinner)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.secondsToWaitSpinner2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.secondsToWaitSpinner3)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.secondsToWaitSpinner3);
            this.groupBox2.Controls.Add(this.label11);
            this.groupBox2.Controls.Add(this.progressButton3);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.secondsToWaitSpinner2);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.progressButton2);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.secondsToWaitSpinner);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.progressButton);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.stopButton);
            this.groupBox2.Controls.Add(this.startButton);
            this.groupBox2.Controls.Add(this.statusStrip);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Location = new System.Drawing.Point(0, 0);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(236, 218);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Marquee Progress Bar";
            // 
            // stopButton
            // 
            this.stopButton.Location = new System.Drawing.Point(80, 38);
            this.stopButton.Name = "stopButton";
            this.stopButton.Size = new System.Drawing.Size(45, 23);
            this.stopButton.TabIndex = 2;
            this.stopButton.Text = "Stop";
            this.stopButton.UseVisualStyleBackColor = true;
            this.stopButton.Click += new System.EventHandler(this.stopButton_Click);
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(9, 38);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(42, 23);
            this.startButton.TabIndex = 1;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.marqueeProgressBar});
            this.statusStrip.Location = new System.Drawing.Point(3, 193);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(230, 22);
            this.statusStrip.TabIndex = 0;
            this.statusStrip.Text = "statusStrip1";
            // 
            // marqueeProgressBar
            // 
            this.marqueeProgressBar.Name = "marqueeProgressBar";
            this.marqueeProgressBar.Size = new System.Drawing.Size(100, 16);
            // 
            // timer
            // 
            this.timer.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(52, 43);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(28, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "then";
            // 
            // progressButton
            // 
            this.progressButton.Location = new System.Drawing.Point(9, 80);
            this.progressButton.Name = "progressButton";
            this.progressButton.Size = new System.Drawing.Size(61, 23);
            this.progressButton.TabIndex = 4;
            this.progressButton.Text = "Progress";
            this.progressButton.UseVisualStyleBackColor = true;
            this.progressButton.Click += new System.EventHandler(this.progressButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(74, 85);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(19, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "for";
            // 
            // secondsToWaitSpinner
            // 
            this.secondsToWaitSpinner.Location = new System.Drawing.Point(99, 81);
            this.secondsToWaitSpinner.Name = "secondsToWaitSpinner";
            this.secondsToWaitSpinner.Size = new System.Drawing.Size(42, 20);
            this.secondsToWaitSpinner.TabIndex = 6;
            this.secondsToWaitSpinner.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(143, 85);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "seconds";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(142, 127);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(47, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "seconds";
            // 
            // secondsToWaitSpinner2
            // 
            this.secondsToWaitSpinner2.Location = new System.Drawing.Point(98, 123);
            this.secondsToWaitSpinner2.Name = "secondsToWaitSpinner2";
            this.secondsToWaitSpinner2.Size = new System.Drawing.Size(42, 20);
            this.secondsToWaitSpinner2.TabIndex = 10;
            this.secondsToWaitSpinner2.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(73, 127);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(19, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "for";
            // 
            // progressButton2
            // 
            this.progressButton2.Location = new System.Drawing.Point(9, 122);
            this.progressButton2.Name = "progressButton2";
            this.progressButton2.Size = new System.Drawing.Size(61, 23);
            this.progressButton2.TabIndex = 8;
            this.progressButton2.Text = "Progress";
            this.progressButton2.UseVisualStyleBackColor = true;
            this.progressButton2.Click += new System.EventHandler(this.progressButton2_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label6.Location = new System.Drawing.Point(6, 22);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(115, 15);
            this.label6.TabIndex = 13;
            this.label6.Text = "Using Buttons (works):";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label7.Location = new System.Drawing.Point(6, 64);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(186, 15);
            this.label7.TabIndex = 14;
            this.label7.Text = "Before and After Code (doesn\'t work):";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label8.Location = new System.Drawing.Point(6, 106);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(140, 15);
            this.label8.TabIndex = 15;
            this.label8.Text = "Using Timer (doesn\'t work)::";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label9.Location = new System.Drawing.Point(6, 148);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(218, 15);
            this.label9.TabIndex = 16;
            this.label9.Text = "Using BackGround Worker Process (works):";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(142, 169);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(47, 13);
            this.label10.TabIndex = 20;
            this.label10.Text = "seconds";
            // 
            // secondsToWaitSpinner3
            // 
            this.secondsToWaitSpinner3.Location = new System.Drawing.Point(98, 165);
            this.secondsToWaitSpinner3.Name = "secondsToWaitSpinner3";
            this.secondsToWaitSpinner3.Size = new System.Drawing.Size(42, 20);
            this.secondsToWaitSpinner3.TabIndex = 19;
            this.secondsToWaitSpinner3.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(73, 169);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(19, 13);
            this.label11.TabIndex = 18;
            this.label11.Text = "for";
            // 
            // progressButton3
            // 
            this.progressButton3.Location = new System.Drawing.Point(9, 164);
            this.progressButton3.Name = "progressButton3";
            this.progressButton3.Size = new System.Drawing.Size(61, 23);
            this.progressButton3.TabIndex = 17;
            this.progressButton3.Text = "Progress";
            this.progressButton3.UseVisualStyleBackColor = true;
            this.progressButton3.Click += new System.EventHandler(this.progressButton3_Click);
            // 
            // backgroundWorker
            // 
            this.backgroundWorker.WorkerReportsProgress = true;
            this.backgroundWorker.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker_DoWork);
            this.backgroundWorker.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.backgroundWorker_RunWorkerCompleted);
            // 
            // MarqueeProgress
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox2);
            this.Name = "MarqueeProgress";
            this.Size = new System.Drawing.Size(236, 218);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.secondsToWaitSpinner)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.secondsToWaitSpinner2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.secondsToWaitSpinner3)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button stopButton;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripProgressBar marqueeProgressBar;
        private System.Windows.Forms.Timer timer;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button progressButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown secondsToWaitSpinner;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown secondsToWaitSpinner2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button progressButton2;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.NumericUpDown secondsToWaitSpinner3;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Button progressButton3;
        private System.ComponentModel.BackgroundWorker backgroundWorker;
    }
}
