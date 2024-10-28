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

    TreeNode* get(vector<int> pre, vector<int> in,
    int pl,int ph,int il,int ih){
        //base condition:
        if(pl>ph)   return NULL;
        if(pl==ph)  return new TreeNode(pre[pl]);
        TreeNode* root=new TreeNode(pre[pl]);
        //Finding process:
        int i=il;
        while(i<=ih){
            if(in[i]==pre[pl])  break ;
            i++;
        }
        int l=i-il;
        int r=ih-i;
        root->left=get(pre,in,pl+1,pl+l,il,i-1);
        root->right=get(pre,in,pl+l+1,ph,i+1,ih);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return get(pre,in,0,pre.size()-1,0,in.size()-1);
    }
};