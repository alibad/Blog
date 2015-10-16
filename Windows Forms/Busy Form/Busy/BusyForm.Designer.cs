namespace Busy
{
    partial class BusyForm
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.waitCursor1 = new Busy.WaitCursor();
            this.marqueeProgress1 = new Busy.MarqueeProgress();
            this.realProgress1 = new Busy.RealProgress();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.waitCursor1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.marqueeProgress1, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.realProgress1, 0, 2);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 3;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20.68966F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 79.31035F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 185F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(236, 464);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // waitCursor1
            // 
            this.waitCursor1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.waitCursor1.Location = new System.Drawing.Point(3, 3);
            this.waitCursor1.Name = "waitCursor1";
            this.waitCursor1.Size = new System.Drawing.Size(230, 51);
            this.waitCursor1.TabIndex = 0;
            // 
            // marqueeProgress1
            // 
            this.marqueeProgress1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.marqueeProgress1.Location = new System.Drawing.Point(3, 60);
            this.marqueeProgress1.Name = "marqueeProgress1";
            this.marqueeProgress1.Size = new System.Drawing.Size(230, 215);
            this.marqueeProgress1.TabIndex = 1;
            // 
            // realProgress1
            // 
            this.realProgress1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.realProgress1.Location = new System.Drawing.Point(3, 281);
            this.realProgress1.Name = "realProgress1";
            this.realProgress1.Size = new System.Drawing.Size(230, 180);
            this.realProgress1.TabIndex = 2;
            // 
            // BusyForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(236, 464);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "BusyForm";
            this.Text = "Busy Form";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private WaitCursor waitCursor1;
        private MarqueeProgress marqueeProgress1;
        private RealProgress realProgress1;
    }
}

