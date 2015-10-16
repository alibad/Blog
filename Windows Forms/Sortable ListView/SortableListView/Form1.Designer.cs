namespace SortableList
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
            this.sortableListView = new SortableListView();
            this.SuspendLayout();
            // 
            // sortableListView
            // 
            this.sortableListView.AllowColumnReorder = true;
            this.sortableListView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.sortableListView.FullRowSelect = true;
            this.sortableListView.Location = new System.Drawing.Point(0, 0);
            this.sortableListView.Name = "sortableListView";
            this.sortableListView.ShowItemToolTips = true;
            this.sortableListView.Size = new System.Drawing.Size(398, 181);
            this.sortableListView.TabIndex = 0;
            this.sortableListView.UseCompatibleStateImageBehavior = false;
            this.sortableListView.View = System.Windows.Forms.View.Details;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(398, 181);
            this.Controls.Add(this.sortableListView);
            this.Name = "Form1";
            this.Text = "Sortable ListView";
            this.ResumeLayout(false);

        }

        #endregion

        private SortableListView sortableListView;
    }
}

