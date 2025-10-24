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

    TreeNode* getAns(vector<int> &preorder,int &i,int range){
        if(i==preorder.size() || preorder[i]>range) return NULL;
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=getAns(preorder,i,root->val);
        root->right=getAns(preorder,i,range);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return getAns(preorder,i,INT_MAX);
    }
};