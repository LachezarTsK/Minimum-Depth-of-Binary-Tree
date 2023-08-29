
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        int depthLevel = 0;
        boolean leafNodeFound = false;

        while (!queue.isEmpty() && !leafNodeFound) {
            ++depthLevel;
            int nodesInDepthLevel = queue.size();

            while (nodesInDepthLevel-- > 0) {
                TreeNode current = queue.poll();
                if (isLeafNode(current)) {
                    leafNodeFound = true;
                    break;
                }
                if (current.left != null) {
                    queue.add(current.left);
                }
                if (current.right != null) {
                    queue.add(current.right);
                }
            }
        }
        return depthLevel;
    }

    private boolean isLeafNode(TreeNode node) {
        return node.left == null && node.right == null;
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
