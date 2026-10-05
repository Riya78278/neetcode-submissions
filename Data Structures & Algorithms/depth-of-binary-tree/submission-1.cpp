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
    int dfs(int dept,TreeNode* root){
        if(root==nullptr){
            return dept;
        }
        int left=dfs(dept+1,root->left);
        int right=dfs(dept+1,root->right);
        int ans=max(left,right);
        return ans;
    }    
public:
    int maxDepth(TreeNode* root) {
        return dfs(0,root);
    }
};
