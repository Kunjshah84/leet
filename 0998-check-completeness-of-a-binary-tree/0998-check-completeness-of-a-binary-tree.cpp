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

    int get_cnt(TreeNode* root){
        if(!root)   return 0;
        return 1+get_cnt(root->left)+get_cnt(root->right);
    }

    bool CBT(TreeNode* root,int ind,int size){
        if(!root)   return 1;
        if(ind>size)    return 0;
        if(!CBT(root->left,(ind*2)+1,size) 
        || !CBT(root->right,(ind*2)+2,size))        return 0;
        return 1;
    }

public:
    bool isCompleteTree(TreeNode* root) {
        return CBT(root,0,get_cnt(root)-1);
    }
};