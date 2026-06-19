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
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        int count=0;
        inorder(root,v);
        if(v.size()==1)
            return true;
        for(int i=0;i<v.size()-1;i++){
            cout<<v[i]<<" ";
            if(v[i]<v[i+1]){
                count++;
            }
        }
        if(count==v.size()-1)
            return true;
        else
            return false;
    }
    void inorder(TreeNode* root, vector<int>& v){
        if(root==NULL)  
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
};
