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
        vector<int> ans;
        vector<vector<int>> v;
        dfs(root,v,0);
        cout<<v.size();
        for(auto it:v){
            ans.push_back(it[it.size()-1]);
        }
        return ans;
    }
    void dfs(TreeNode* root, vector<vector<int>>& v, int n){
        if(root==NULL)
            return;
        if(n==v.size())
            v.push_back(vector<int>());
        v[n].push_back(root->val);
        dfs(root->left,v,n+1);
        dfs(root->right,v,n+1);
    }
};
