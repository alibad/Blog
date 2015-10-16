using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace RegexUI
{
    public partial class RegexUI : Form
    {
        public RegexUI()
        {
            InitializeComponent();
        }

        private void regexTextBox_TextChanged(object sender, EventArgs e)
        {
            RunRegexCheck();
        }

        private void inputTextBox_TextChanged(object sender, EventArgs e)
        {
            RunRegexCheck();
        }

        private void RunRegexCheck()
        {
            matchesList.BeginUpdate();
            matchesList.Items.Clear();

            if (regexTextBox.Text != string.Empty)
            {
                
                try
                {
                    foreach (Match match in Regex.Matches(inputTextBox.Text, regexTextBox.Text, RegexOptions.Singleline))
                    {
                        ListViewItem item = matchesList.Items.Add(match.Value);
                        item.SubItems.Add(match.Index.ToString());
                        item.SubItems.Add(match.Length.ToString());
                        
                    }
                }
                catch (Exception e)
                {
                    ListViewItem item = matchesList.Items.Add(e.Message);
                    item.ForeColor = Color.Red;
                }
            }

            matchesList.EndUpdate();
        }

        private void matchesList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (matchesList.SelectedItems.Count > 0)
            {
                ListViewItem item = matchesList.SelectedItems[0];
                detailsTextBox.Text = item.Text;
            }
            else
            {
                detailsTextBox.Text = string.Empty;
            }
        }
    }
}