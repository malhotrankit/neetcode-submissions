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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return nullptr;
        if(root==p||root==q)
            return root;
        TreeNode* lt = lowestCommonAncestor(root->left,p,q);
        TreeNode* rt = lowestCommonAncestor(root->right,p,q);
        if(lt != nullptr && rt != nullptr)
            return root;
        if(lt != nullptr)
            return lt;
        else
            return rt;
    }
};
