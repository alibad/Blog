namespace SPIcon
{
    partial class spIconForm
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(spIconForm));
            this.splitContainer = new System.Windows.Forms.SplitContainer();
            this.siteCollectionList = new System.Windows.Forms.ListView();
            this.tableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.panel = new System.Windows.Forms.Panel();
            this.urlTextBox = new System.Windows.Forms.TextBox();
            this.urlLabel = new System.Windows.Forms.Label();
            this.spTreeView = new System.Windows.Forms.TreeView();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.statusMessageLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.statusToolTip = new System.Windows.Forms.ToolTip(this.components);
            this.spImageList = new System.Windows.Forms.ImageList(this.components);
            this.splitContainer.Panel1.SuspendLayout();
            this.splitContainer.Panel2.SuspendLayout();
            this.splitContainer.SuspendLayout();
            this.tableLayoutPanel.SuspendLayout();
            this.panel.SuspendLayout();
            this.statusStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer
            // 
            this.splitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer.Location = new System.Drawing.Point(0, 0);
            this.splitContainer.Name = "splitContainer";
            this.splitContainer.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer.Panel1
            // 
            this.splitContainer.Panel1.Controls.Add(this.siteCollectionList);
            // 
            // splitContainer.Panel2
            // 
            this.splitContainer.Panel2.Controls.Add(this.tableLayoutPanel);
            this.splitContainer.Size = new System.Drawing.Size(292, 451);
            this.splitContainer.SplitterDistance = 89;
            this.splitContainer.TabIndex = 1;
            // 
            // siteCollectionList
            // 
            this.siteCollectionList.CheckBoxes = true;
            this.siteCollectionList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.siteCollectionList.Location = new System.Drawing.Point(0, 0);
            this.siteCollectionList.Name = "siteCollectionList";
            this.siteCollectionList.Size = new System.Drawing.Size(292, 89);
            this.siteCollectionList.TabIndex = 2;
            this.siteCollectionList.UseCompatibleStateImageBehavior = false;
            this.siteCollectionList.View = System.Windows.Forms.View.SmallIcon;
            this.siteCollectionList.ItemChecked += new System.Windows.Forms.ItemCheckedEventHandler(this.siteCollectionList_ItemChecked);
            // 
            // tableLayoutPanel
            // 
            this.tableLayoutPanel.ColumnCount = 1;
            this.tableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel.Controls.Add(this.panel, 0, 1);
            this.tableLayoutPanel.Controls.Add(this.spTreeView, 0, 0);
            this.tableLayoutPanel.Controls.Add(this.statusStrip, 0, 2);
            this.tableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel.Name = "tableLayoutPanel";
            this.tableLayoutPanel.RowCount = 3;
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 30F));
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel.Size = new System.Drawing.Size(292, 358);
            this.tableLayoutPanel.TabIndex = 0;
            // 
            // panel
            // 
            this.panel.Controls.Add(this.urlTextBox);
            this.panel.Controls.Add(this.urlLabel);
            this.panel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel.Location = new System.Drawing.Point(3, 311);
            this.panel.Name = "panel";
            this.panel.Size = new System.Drawing.Size(286, 24);
            this.panel.TabIndex = 2;
            // 
            // urlTextBox
            // 
            this.urlTextBox.Location = new System.Drawing.Point(61, 1);
            this.urlTextBox.Name = "urlTextBox";
            this.urlTextBox.ReadOnly = true;
            this.urlTextBox.Size = new System.Drawing.Size(222, 20);
            this.urlTextBox.TabIndex = 1;
            // 
            // urlLabel
            // 
            this.urlLabel.AutoSize = true;
            this.urlLabel.Location = new System.Drawing.Point(3, 5);
            this.urlLabel.Name = "urlLabel";
            this.urlLabel.Size = new System.Drawing.Size(52, 13);
            this.urlLabel.TabIndex = 1;
            this.urlLabel.Text = "Image Url";
            // 
            // spTreeView
            // 
            this.spTreeView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spTreeView.ImageIndex = 0;
            this.spTreeView.ImageList = this.spImageList;
            this.spTreeView.Location = new System.Drawing.Point(3, 3);
            this.spTreeView.Name = "spTreeView";
            this.spTreeView.SelectedImageIndex = 0;
            this.spTreeView.Size = new System.Drawing.Size(286, 302);
            this.spTreeView.TabIndex = 3;
            this.spTreeView.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.spTreeView_AfterSelect);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusMessageLabel});
            this.statusStrip.Location = new System.Drawing.Point(0, 338);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(292, 20);
            this.statusStrip.TabIndex = 4;
            this.statusStrip.Text = "statusStrip1";
            // 
            // statusMessageLabel
            // 
            this.statusMessageLabel.Name = "statusMessageLabel";
            this.statusMessageLabel.Size = new System.Drawing.Size(38, 15);
            this.statusMessageLabel.Text = "Status";
            // 
            // spImageList
            // 
            this.spImageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("spImageList.ImageStream")));
            this.spImageList.TransparentColor = System.Drawing.Color.Transparent;
            this.spImageList.Images.SetKeyName(0, "site.png");
            this.spImageList.Images.SetKeyName(1, "subwebs.png");
            this.spImageList.Images.SetKeyName(2, "root.png");
            this.spImageList.Images.SetKeyName(3, "web.png");
            this.spImageList.Images.SetKeyName(4, "lists.png");
            this.spImageList.Images.SetKeyName(5, "library.png");
            this.spImageList.Images.SetKeyName(6, "ct.png");
            this.spImageList.Images.SetKeyName(7, "folder.png");
            // 
            // spIconForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(292, 451);
            this.Controls.Add(this.splitContainer);
            this.Name = "spIconForm";
            this.Text = "SPIcon";
            this.Load += new System.EventHandler(this.SPIcon_Load);
            this.splitContainer.Panel1.ResumeLayout(false);
            this.splitContainer.Panel2.ResumeLayout(false);
            this.splitContainer.ResumeLayout(false);
            this.tableLayoutPanel.ResumeLayout(false);
            this.tableLayoutPanel.PerformLayout();
            this.panel.ResumeLayout(false);
            this.panel.PerformLayout();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer;
        private System.Windows.Forms.ListView siteCollectionList;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel;
        private System.Windows.Forms.Panel panel;
        private System.Windows.Forms.TextBox urlTextBox;
        private System.Windows.Forms.Label urlLabel;
        private System.Windows.Forms.TreeView spTreeView;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolTip statusToolTip;
        private System.Windows.Forms.ToolStripStatusLabel statusMessageLabel;
        private System.Windows.Forms.ImageList spImageList;
    }
}

