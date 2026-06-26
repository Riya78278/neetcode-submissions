/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {  
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        return isSubTreePresent(root, subRoot);
    }

    private boolean isSubTreePresent(TreeNode root, TreeNode subRoot) {
        // base condition
        if (root == null) {
            return false;
        }
        if (checkEqual(root, subRoot)) {
            return true;
        }

        boolean left = isSubTreePresent(root.left, subRoot);
        boolean right = isSubTreePresent(root.right, subRoot);

        return left || right;
    }

    private boolean checkEqual(TreeNode root, TreeNode subRoot) {
        if (root == null && subRoot == null) {
            return true;
        }
        if (root == null || subRoot == null) {
            return false;
        }
        if (root.val != subRoot.val) {
            return false;
        }
        
        return checkEqual(root.left, subRoot.left) && checkEqual(root.right, subRoot.right);
    }
}

