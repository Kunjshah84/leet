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
    int sum=0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)   return sum;
        rangeSumBST(root->left,low,high);
        sum= (root->val>=low && root->val<=high) ? sum+root->val : sum; 
        rangeSumBST(root->right,low,high);
        return sum;
    }
};