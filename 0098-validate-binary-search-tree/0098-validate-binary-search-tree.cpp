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
    long long int max_val(TreeNode* root){
        if(!root)   return LLONG_MIN;
        return max((long long int)root->val,max(max_val(root->left),max_val(root->right)));
    }
    long long int min_val(TreeNode* root){
        if(!root)   return LLONG_MAX;
        return min((long long int)root->val,min(min_val(root->left),min_val(root->right)));
    }

public:
    bool isValidBST(TreeNode* root) {
        if(!root)   return 1;
        if((long long int)root->val>max_val(root->left) 
        && (long long int)root->val<min_val(root->right) 
        && (isValidBST(root->left) & isValidBST(root->right)))  return 1;
        return 0;
    }
};