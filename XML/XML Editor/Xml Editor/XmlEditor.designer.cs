using System.Windows.Forms;


public partial class XmlEditor : UserControl
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
        this.xmlTextBox = new System.Windows.Forms.RichTextBox();
        this.SuspendLayout();
        // 
        // xmlTextBox
        // 
        this.xmlTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
        this.xmlTextBox.Location = new System.Drawing.Point(0, 0);
        this.xmlTextBox.Name = "xmlTextBox";
        this.xmlTextBox.Size = new System.Drawing.Size(150, 150);
        this.xmlTextBox.TabIndex = 0;
        this.xmlTextBox.Text = "";
        this.xmlTextBox.TextChanged += new System.EventHandler(this.xmlTextBox_TextChanged);
        // 
        // XmlEditor
        // 
        this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.Controls.Add(this.xmlTextBox);
        this.Name = "XmlEditor";
        this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.RichTextBox xmlTextBox;
}
