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
private:
    void counting(TreeNode* root,int max, int &count){
        if(root== nullptr){
            return;
        }
        if(root->val>=max){
            max=root->val;
            count++;
        }
        counting(root->left,max,count);
        counting(root->right,max,count);

    }    
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        counting(root,root->val,count);
        return count;
    }
};