/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
public:
    // Function to calculate maximum path sum and update the global max
    int path(TreeNode* root, int& globalMax) {
        if (root == nullptr) {
            return 0;
        }
        
        // Compute the maximum path sum of the left and right subtrees
        int left = max(path(root->left, globalMax), 0); // If negative, ignore
        int right = max(path(root->right, globalMax), 0); // If negative, ignore
        
        // Update global maximum path sum
        int localMax = root->val + left + right;
        globalMax = max(globalMax, localMax);
        
        // Return the maximum path sum including the current node
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN; // Initialize globalMax to the smallest possible integer
        path(root, globalMax);
        return globalMax;
    }
};
