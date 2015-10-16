using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;

using Microsoft.SharePoint;
using Microsoft.SharePoint.Administration;
using Microsoft.SharePoint.Utilities;

namespace SPIcon
{
    public partial class spIconForm : Form
    {
        #region Instance Variables

        //  Status Message to be communicated with the user
        protected MessagePack statusMessage;

        #endregion

        #region Initialization

        /// <summary>
        /// Constructor
        /// </summary>
        public spIconForm()
        {
            //  Initialize components
            InitializeComponent();
        }

        #endregion

        #region UI Events

        /// <summary>
        /// Form Load Event
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void SPIcon_Load(object sender, EventArgs e)
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

        /// <summary>
        /// Event triggered when an item is checked in the site collection list
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void siteCollectionList_ItemChecked(object sender, ItemCheckedEventArgs e)
        {
            Cursor.Current = Cursors.WaitCursor;

            //  Load tree based on selected site collections
            UpdateSPTree(e.Item.Text, e.Item.Checked);
            
            Cursor.Current = Cursors.Default;
        }

        /// <summary>
        /// Triggered after a tree node is selected.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void spTreeView_AfterSelect(object sender, TreeViewEventArgs e)
        {
            object tag = spTreeView.SelectedNode.Tag;
            if (tag != null)
            {
                urlTextBox.Text = tag.ToString();
            }
            else
            {
                urlTextBox.Text = string.Empty;
            }
        }

        #endregion

        #region Helper Methods

        /// <summary>
        /// Updates the SP tree based on selected site collections
        /// </summary>
        /// <param name="siteUrl">Url of the site collection</param>
        /// <param name="add">whether to add or remove the site collection from the tree</param>
        private void UpdateSPTree(string siteUrl, bool add)
        {
            //  Get the site node
            TreeNode siteNode = spTreeView.Nodes[siteUrl];

            //  Unexpected case
            if (siteNode == null ^ add)
            {
                return;
            }

            //  Begin updating Tree
            spTreeView.BeginUpdate();

            try
            {
                if (add)
                {
                    //  Selected site collection node
                    siteNode = spTreeView.Nodes.Add(siteUrl, siteUrl);
                    siteNode.SelectedImageIndex = siteNode.ImageIndex = 0;

                    //  Create the SPSite object
                    using (SPSite site = new SPSite(siteUrl))
                    {
                        //  Get the site root web
                        using (SPWeb rootWeb = site.RootWeb)
                        {
                            TreeNode rootNode = AddWebSubTree(rootWeb);
                            rootNode.SelectedImageIndex = rootNode.ImageIndex = 1;
                            siteNode.Nodes.Add(rootNode);

                            //  Expand root web node
                            rootNode.Expand();
                        }
                    }

                    //  Expand site node
                    siteNode.Expand();
                }
                else
                {
                    if (siteNode != null)
                    {
                        //  Make sure the site node and all itssub nodes are un-checked
                        siteNode.Checked = false;

                        //  Remove the node
                        spTreeView.Nodes.Remove(siteNode);
                    }
                }
            }
            catch (Exception e)
            {
                statusMessage.Message = e.Message;
                statusMessage.Exception = e;
                CommunicateStatus();
            }

            //  Finish updating Tree
            spTreeView.EndUpdate();
        }

        /// <summary>
        /// Builds the web subtree
        /// </summary>
        /// <param name="web"></param>
        private TreeNode AddWebSubTree(SPWeb web)
        {
            //  Add the web node
            TreeNode webNode = new TreeNode(web.Title);
            webNode.SelectedImageIndex = webNode.ImageIndex = 3;

            TreeNode listsNode = webNode.Nodes.Add("Lists");
            listsNode.SelectedImageIndex = listsNode.ImageIndex = 4;
            TreeNode librariesNode = webNode.Nodes.Add("Libraries");
            librariesNode.SelectedImageIndex = librariesNode.ImageIndex = 5;
            foreach (SPList list in web.Lists)
            {
                //  Determine list parent node
                TreeNode parentNode = null;
                if (list.BaseType == SPBaseType.DocumentLibrary)
                {
                    parentNode = librariesNode;
                }
                else
                {
                    parentNode = listsNode;
                }

                //  Add lists to the tree
                TreeNode listNode = parentNode.Nodes.Add(list.Title);
                listNode.SelectedImageIndex = listNode.ImageIndex = GetImage(GetImageFullPath(list.ImageUrl));
                listNode.Tag = list.ImageUrl;

                //  Add files to the document library tree node
                if(parentNode == librariesNode)
                {
                    SPDocumentLibrary library = (SPDocumentLibrary)list;
                    AddFilesSubTree(listNode, library.RootFolder);
                }
            }

            TreeNode contentTypesNode = webNode.Nodes.Add("Content Types");
            contentTypesNode.SelectedImageIndex = contentTypesNode.ImageIndex = 6;
            foreach (SPContentType contentType in web.ContentTypes)
            {
                TreeNode groupNode = contentTypesNode.Nodes[contentType.Group];

                if (groupNode == null)
                {
                    groupNode = contentTypesNode.Nodes.Add(contentType.Group, contentType.Group);
                }

                groupNode.SelectedImageIndex = groupNode.ImageIndex = 6;

                //  Add content types to the tree
                TreeNode ctNode = groupNode.Nodes.Add(contentType.Name);
                ctNode.SelectedImageIndex = ctNode.ImageIndex = 6;
            }

            //  Build the nodes for subwebs of this web
            TreeNode subWebsNode = webNode.Nodes.Add("Subwebs");
            subWebsNode.SelectedImageIndex = subWebsNode.ImageIndex = 2;
            foreach (SPWeb subweb in web.Webs)
            {
                subWebsNode.Nodes.Add(AddWebSubTree(subweb));
                subweb.Close();
            }

            return webNode;
        }

        /// <summary>
        /// Builds the file subtree
        /// </summary>
        /// <param name="parentNode"></param>
        /// <param name="parentFolder"></param>
        private void AddFilesSubTree(TreeNode parentNode, SPFolder parentFolder)
        {
            //  Add the subfolders
            foreach (SPFolder subFolder in parentFolder.SubFolders)
            {
                TreeNode folderNode = parentNode.Nodes.Add(subFolder.Name);
                folderNode.SelectedImageIndex = folderNode.ImageIndex = 7;
                AddFilesSubTree(folderNode, subFolder);
            }

            //  Add the files
            foreach (SPFile file in parentFolder.Files)
            {
                TreeNode fileNode = parentNode.Nodes.Add(file.Name);
                fileNode.SelectedImageIndex = fileNode.ImageIndex = GetImage(GetImageFullPath(file.IconUrl));
                fileNode.Tag = file.IconUrl;
            }
        }

        /// <summary>
        /// Gets the SharePoint full path from the relative path
        /// </summary>
        /// <param name="relativePath"></param>
        /// <returns></returns>
        private static string GetImageFullPath(string relativePath)
        {
            //  Get image name
            string imageName = Path.GetFileName(relativePath);

            //  Get SharePoint IMAGES folder path
            string fullPath = SPUtility.GetGenericSetupPath(@"TEMPLATE\IMAGES");

            return Path.Combine(fullPath, imageName);
        }

        /// <summary>
        /// Gets the image of the sp element from specified url
        /// </summary>
        /// <param name="url"></param>
        /// <returns></returns>
        private int GetImage(string url)
        {
            //  Get image index from the Image List
            int imageIndex = spImageList.Images.IndexOfKey(url);

            //  Image is not in the list, so add it
            if (imageIndex == -1)
            {
                //  Get the image from specified path
                Image image = Image.FromFile(url);

                //  Add the image to the image list
                spImageList.Images.Add(url, image);

                //  Get its index
                imageIndex = spImageList.Images.Count - 1;
            }

            return imageIndex;
        }

        /// <summary>
        /// Communicates the status message with the user.
        /// </summary>
        protected void CommunicateStatus()
        {
            statusMessageLabel.Text = statusMessage.Message;
            statusToolTip.SetToolTip(statusStrip, statusMessage.Details);

            if (statusMessage.Type == MessageType.Error)
            {
                statusMessageLabel.ForeColor = Color.Red;
                statusToolTip.ToolTipIcon = ToolTipIcon.Error;
                statusToolTip.ToolTipTitle = "Error";
            }
            else if (statusMessage.Type == MessageType.Info)
            {
                statusMessageLabel.ForeColor = Color.Black;
                statusToolTip.ToolTipIcon = ToolTipIcon.Info;
                statusToolTip.ToolTipTitle = "Details";
            }
        }

        #endregion
    }
}
