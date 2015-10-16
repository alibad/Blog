using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SortableList
{
    public partial class Form1 : Form
    {
        /// <summary>
        /// Constructor
        /// </summary>
        public Form1()
        {
            InitializeComponent();

            AddColumns();
            AddItems();
            sortableListView.AutoResizeColumns(ColumnHeaderAutoResizeStyle.ColumnContent);
        }

        /// <summary>
        /// Add columns to the list view
        /// </summary>
        private void AddColumns()
        {
            sortableListView.Columns.Add("String Field").Tag = typeof(string);
            sortableListView.Columns.Add("DateTime Field").Tag = typeof(DateTime);
            sortableListView.Columns.Add("Int Field").Tag = typeof(int);
            sortableListView.Columns.Add("Double Field").Tag = typeof(double);
        }

        /// <summary>
        /// Add items to the list view
        /// </summary>
        private void AddItems()
        {
            Random randomGenerator = new Random();
            int totalItems = randomGenerator.Next(25, 100);

            for (int i = 0; i < totalItems; i++)
            {
                ListViewItem item = new ListViewItem();

                //  Add String
                item.Text = string.Format("String {0}", randomGenerator.Next());

                //  Add Datetime
                DateTime date = new DateTime(randomGenerator.Next(3000), 
                                             randomGenerator.Next(1, 13),
                                             randomGenerator.Next(1, 29));
                item.SubItems.Add(date.ToString());

                //  Add int
                item.SubItems.Add(i.ToString());

                //  Add double
                double d = randomGenerator.NextDouble() * i;
                item.SubItems.Add(d.ToString());

                sortableListView.Items.Add(item);
            }
        }
    }
}
