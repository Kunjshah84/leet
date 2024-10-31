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

    TreeNode* get(vector<int> pre,vector<int> in,int ps,int pe,int is,int ie){
        if(ps>pe)   return NULL;
        if(ps==pe)  return new TreeNode(pre[ps]);
        TreeNode* root=new TreeNode(pre[ps]);
        int i=is;
        while(i<=ie && in[i]!=pre[ps])    i++;
        int lc=i-is;
        root->left=get(pre,in,ps+1,ps+lc,is,i);
        root->right=get(pre,in,ps+lc+1,pe,i+1,ie);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return get(pre,in,0,pre.size()-1,0,pre.size()-1);
    }
};