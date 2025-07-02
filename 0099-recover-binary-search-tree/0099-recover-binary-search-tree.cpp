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
    TreeNode* pre=NULL;
    TreeNode* first=NULL;
    TreeNode* midd=NULL;
    TreeNode* last=NULL;

    void get(TreeNode* root){
        if(!root)   return ;
        get(root->left);
        if(!pre)   pre=root;
        else if(root->val < pre->val && !first){
            first=pre;
            midd=root;
        }
        else if(root->val < pre->val && !last)    last=root;
        pre=root;
        get(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        get(root);
        if(last)    swap(first->val,last->val);
        else    swap(first->val,midd->val);
    }
};