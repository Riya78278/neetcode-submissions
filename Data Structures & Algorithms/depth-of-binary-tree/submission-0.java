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
    public int maxDepth(TreeNode root) {
        ///base condition
        return dfs(0, root);
    }
    private int dfs(int dep, TreeNode root) {
        if(root == null) {
            return dep;
        }
        int left = dfs(dep+1, root.left);
        int right = dfs(dep+1, root.right);
        return Math.max(left, right);
    }
}
