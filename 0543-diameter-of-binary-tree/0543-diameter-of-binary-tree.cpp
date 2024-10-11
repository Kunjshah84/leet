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

    int get(int &ans,TreeNode* root){
        if(!root)   return 0;
        int left=get(ans,root->left);
        int right=get(ans,root->right);
        ans=max(ans,left+right);
        return max(left,right)+1; 
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        get(ans,root);
        return ans;
    }
};