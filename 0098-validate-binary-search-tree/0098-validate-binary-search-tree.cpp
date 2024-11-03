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
    long long int pre=LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if(!root)   return 1;
        if(isValidBST(root->left) && root->val>pre){
            pre=root->val;
            return isValidBST(root->right);
        }
        return 0;
    }
};