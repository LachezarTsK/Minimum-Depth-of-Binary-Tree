
using System;
using System.Collections.Generic;

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution
{
    public int MinDepth(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }

        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        int depthLevel = 0;
        bool leafNodeFound = false;

        while (queue.Count > 0 && !leafNodeFound)
        {
            ++depthLevel;
            int nodesInDepthLevel = queue.Count;

            while (nodesInDepthLevel-- > 0)
            {
                TreeNode current = queue.Dequeue();
                if (isLeafNode(current))
                {
                    leafNodeFound = true;
                    break;
                }
                if (current.left != null)
                {
                    queue.Enqueue(current.left);
                }
                if (current.right != null)
                {
                    queue.Enqueue(current.right);
                }
            }
        }
        return depthLevel;
    }

    private bool isLeafNode(TreeNode node)
    {
        return node.left == null && node.right == null;
    }
}
