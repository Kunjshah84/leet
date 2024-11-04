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

    void get(TreeNode* &root,int low,int high){
        if(!root)   return ;
        while(root->left){
            if(root->left->val<low)  root->left=root->left->right;
            else if(root->left->val>high)    root->left=root->left->left;
            else    break ;
        }
        while(root->right){
            if(root->right->val>high)  root->right=root->right->left;
            else if(root->right->val<low)    root->right=root->right->right;
            else    break ;
        }
        get(root->left,low,high);
        get(root->right,low,high);
    }

public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        get(dummy,low,high);
        return dummy->left;
    }
};