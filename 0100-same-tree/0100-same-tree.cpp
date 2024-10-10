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

    bool fun(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2)    return 1; 
        if((!root1 && root2) || (root1 && !root2) || root1->val!=root2->val)
            return 0;
        if(!(fun(root1->left , root2->left))) return 0;
        if(!(fun(root1->right , root2->right))) return 0;
        return 1;
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p,q);
    }
};