using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using Microsoft.SharePoint;
using Microsoft.SharePoint.Administration;

namespace SPSiteList
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //  Load the list of site collections
            foreach (SPWebApplication webApp in SPWebService.ContentService.WebApplications)
            {
                string webAppUrl = webApp.GetResponseUri(SPUrlZone.Default).AbsoluteUri;
                ListViewGroup webAppGroup = new ListViewGroup(webApp.Name, HorizontalAlignment.Left);
                siteCollectionList.Groups.Add(webAppGroup);

                foreach (string siteUrl in webApp.Sites.Names)
                {
                    string fullSiteUrl = webAppUrl + siteUrl;
                    ListViewItem siteItem = new ListViewItem(fullSiteUrl, webAppGroup);
                    siteItem.ToolTipText = siteItem.Text;
                    siteCollectionList.Items.Add(siteItem);
                }
            }

            //  Select the first site collection in the list
            if (siteCollectionList.Items.Count > 0)
            {
                siteCollectionList.Items[0].Checked = true;
            }
        }
    }
}
