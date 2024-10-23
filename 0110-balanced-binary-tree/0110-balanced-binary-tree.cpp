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

    int get(TreeNode* root,bool &flag){
        if(!root)   return 0;
        int ll=get(root->left,flag);
        int rl=get(root->right,flag);
        if(abs(ll-rl)>1)    flag=1;
        return 1+max(ll,rl);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool flag=0;
        get(root,flag);
        return !flag ? 1 : 0;
    }
};