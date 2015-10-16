#region Using Directives

using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Xml;
using System.Collections;
using System.Xml.Serialization;
using System.Reflection;
using System.Text.RegularExpressions;
using Microsoft.Win32;

#endregion

/// <summary>
/// Utility class with helpful static methods.
/// </summary>
public class Utils
{
    /// <summary>
    /// Returns a wrapped version of the very long string.
    /// </summary>
    /// <param name="longString"></param>
    /// <param name="newLine"></param>
    /// <param name="lineLength"></param>
    /// <returns></returns>
    public static string Wrap(string longString, string newLine, int lineLength)
    {
        StringBuilder sb = new StringBuilder(longString);
        int stringLength = sb.Length;

        for (int i = lineLength; i < stringLength; i += lineLength)
        {
            while (i < stringLength)
            {
                if (sb[i] == ' ')
                {
                    sb.Insert(i, newLine);
                    break;
                }

                i++;
            }
        }

        return sb.ToString();
    }

    /// <summary>
    /// Gets the TreeView node text.
    /// </summary>
    /// <param name="node"></param>
    /// <param name="identation"></param>
    /// <returns></returns>
    public static string GetNodeText(TreeNode node, string identation)
    {
        StringBuilder sb = new StringBuilder();
        if (node != null)
        {
            identation += "\t";

            sb.Append(node.Text);
            foreach (TreeNode subnode in node.Nodes)
            {
                sb.Append("\n");
                sb.Append(identation);
                sb.Append(GetNodeText(subnode, identation));
            }
        }

        return sb.ToString();
    }

    /// <summary>
    /// Pushes down the 'Checked' state of the node to all its subnodes (recursively)
    /// </summary>
    /// <param name="node"></param>
    public static void PushDownCheckedState(TreeNode node)
    {
        if (node != null && node.Nodes != null)
        {
            foreach (TreeNode subNode in node.Nodes)
            {
                if (subNode.Checked != node.Checked)
                {
                    subNode.Checked = node.Checked;
                }
                PushDownCheckedState(subNode);
            }
        }
    }
}
