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
    int goodNodes(TreeNode* root) {
        vector<int> v;
        dfs(root,root->val,v);
        return v.size();      
    }
    void dfs(TreeNode* root,int maxi,vector<int>& v){
        if(root==NULL)
            return;
        if(root->val>=maxi){
            maxi=root->val;
            v.push_back(root->val);
        }
        dfs(root->left,maxi,v);
        dfs(root->right,maxi,v);
    }
};
