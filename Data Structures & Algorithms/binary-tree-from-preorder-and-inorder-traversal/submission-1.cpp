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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* node= build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return node;
    }
    TreeNode* build(vector<int>& preorder,int prestart,int preend, vector<int>& inorder,int inistart,int iniend,map<int,int>&mp){
        if(prestart > preend || inistart > iniend) return nullptr;
        TreeNode* node= new TreeNode(preorder[prestart]);
        int inroot= mp[node->val];
        int numstart= inroot - inistart;
        node->left=build(preorder,prestart+1,prestart+numstart,inorder,inistart,inroot-1,mp);
        node->right=build(preorder,prestart+numstart+1,preend,inorder,inroot+1,iniend,mp);
        return node;
    }


};
