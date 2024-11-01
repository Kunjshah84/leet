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

    TreeNode* insert(TreeNode* root,int val){
        if(!root)   return new TreeNode(val);
        if(root->val>val)   root->left=insert(root->left,val);
        else    root->right=insert(root->right,val);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if(!pre.size())   return NULL;
        TreeNode* root=new TreeNode(pre[0]);
        for(int i=1;i<pre.size();i++) insert(root,pre[i]);
        return root;
    }
};