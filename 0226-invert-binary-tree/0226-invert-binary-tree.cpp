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

    void get(TreeNode* root){
        if(!root)   return ;
        get(root->left);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        get(root->left);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        get(root);
        return root;
    }
};