namespace SPSiteList
{
    partial class Form1
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
            this.siteCollectionList = new System.Windows.Forms.ListView();
            this.SuspendLayout();
            // 
            // siteCollectionList
            // 
            this.siteCollectionList.CheckBoxes = true;
            this.siteCollectionList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.siteCollectionList.HoverSelection = true;
            this.siteCollectionList.Location = new System.Drawing.Point(0, 0);
            this.siteCollectionList.Name = "siteCollectionList";
            this.siteCollectionList.Size = new System.Drawing.Size(328, 161);
            this.siteCollectionList.TabIndex = 0;
            this.siteCollectionList.UseCompatibleStateImageBehavior = false;
            this.siteCollectionList.View = System.Windows.Forms.View.SmallIcon;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(328, 161);
            this.Controls.Add(this.siteCollectionList);
            this.Name = "Form1";
            this.Text = "SPSite List";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView siteCollectionList;
    }
}

