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

    bool fun(TreeNode* p,TreeNode* q){
        if(!p && !q)    return 1;
        if(!p || !q)    return 0;
        return (p->val==q->val) && fun(p->left,q->right) && fun(p->right,q->left);
    }   

public:
    bool isSymmetric(TreeNode* root) {
        return fun(root->right,root->left);
    }
};