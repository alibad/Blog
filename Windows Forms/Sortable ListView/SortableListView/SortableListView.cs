using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using System.Collections;
using System.Runtime.InteropServices;

public partial class SortableListView : ListView
{
    //  ListView Current sort column
    private int sortColumn = -1;

    /// <summary>
    /// Constructor
    /// </summary>
    public SortableListView()
    {
        InitializeComponent();

        //  Add Column Click Events
        this.ColumnClick += new ColumnClickEventHandler(list_ColumnClick);

        //  Define properties of the List View
        this.View = View.Details;
        this.AllowColumnReorder = true;
        this.FullRowSelect = true;
        this.ShowItemToolTips = true;
    }

    /// <summary>
    /// Sort when column is clicked.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void list_ColumnClick(object sender, ColumnClickEventArgs e)
    {
        // Determine whether the column is the same as the last column clicked.
        if (e.Column != sortColumn)
        {
            // Set the sort column to the new column.
            sortColumn = e.Column;

            // Set the sort order to ascending by default.
            this.Sorting = SortOrder.Ascending;
        }
        else
        {
            // Determine what the last sort order was and change it.
            if (this.Sorting == SortOrder.Ascending)
                this.Sorting = SortOrder.Descending;
            else
                this.Sorting = SortOrder.Ascending;
        }

        //  Get the column type
        Type type = this.Columns[e.Column].Tag as Type;

        // Set the ListViewItemSorter property to a new ListViewItemComparer object.
        this.ListViewItemSorter = new ListViewItemComparer(e.Column,
                                                           this.Sorting,
                                                           type);
    }

    /// <summary>
    /// Implements the manual sorting of items by column.
    /// </summary>
    public class ListViewItemComparer : IComparer
    {
        private int col;            //  Column to sort by
        private SortOrder order;    //  Sorting Order
        private Type columnType;    //  Type of column

        /// <summary>
        /// Default Constructor
        /// </summary>
        public ListViewItemComparer()
        {
            this.col = 0;
            this.order = SortOrder.Ascending;
            this.columnType = null;
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="column">Column Index in the list</param>
        /// <param name="order">Sorting Order</param>
        /// <param name="type">The type of the column</param>
        public ListViewItemComparer(int column, SortOrder order, Type type)
        {
            this.col = column;
            this.order = order;
            this.columnType = type;
        }

        /// <summary>
        /// Compare the two objects based on the type
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public int Compare(object x, object y)
        {
            int returnVal = -1;

            //  String
            if (columnType == null || columnType == typeof(String))
            {
                returnVal = String.Compare(((ListViewItem)x).SubItems[col].Text,
                                    ((ListViewItem)y).SubItems[col].Text);
            }
            //  DateTime
            else if (columnType == typeof(DateTime))
            {
                returnVal = DateTime.Compare(DateTime.Parse(((ListViewItem)x).SubItems[col].Text),
                                             DateTime.Parse(((ListViewItem)y).SubItems[col].Text));
            }
            //  Int
            else if (columnType == typeof(int))
            {
                int i1 = int.Parse(((ListViewItem)x).SubItems[col].Text);
                int i2 = int.Parse(((ListViewItem)y).SubItems[col].Text);

                returnVal = (i1 - i2);
            }
            else if (columnType == typeof(double))
            {
                double d1 = double.Parse(((ListViewItem)x).SubItems[col].Text);
                double d2 = double.Parse(((ListViewItem)y).SubItems[col].Text);

                if (d1 == d2)
                {
                    returnVal = 0;
                }
                else if (d1 > d2)
                {
                    returnVal = 1;
                }
                else
                {
                    returnVal = -1;
                }
            }

            // Determine whether the sort order is descending.
            if (order == SortOrder.Descending)
            {
                // Invert the value returned by String.Compare.
                returnVal *= -1;
            }

            return returnVal;
        }
    }
}
