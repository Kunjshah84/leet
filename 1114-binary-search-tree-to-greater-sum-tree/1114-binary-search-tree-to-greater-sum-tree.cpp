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
public:

    int get(TreeNode* root){
        if(!root)   return 0;
        return root->val+get(root->left)+get(root->right);
    }

    void help(TreeNode* root,int &t,int sum){
        if(!root)   return ;
        help(root->left,t,sum);
        int temp=root->val;
        root->val=sum-t;
        t+=temp;
        help(root->right,t,sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum=get(root),t=0;
        cout<<sum<<endl;
        help(root,t,sum);
        return root;
    }
};