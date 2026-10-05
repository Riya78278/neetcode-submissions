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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr){
            return ans;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        map<int,int>mp;
        while(!q.empty()){
            auto node=q.front().first;
            int line=q.front().second;
            q.pop();
            mp[line]=node->val;
            if(node->left != nullptr){
                q.push({node->left,line+1});
            }
            if(node->right != nullptr){
                q.push({node->right,line+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
