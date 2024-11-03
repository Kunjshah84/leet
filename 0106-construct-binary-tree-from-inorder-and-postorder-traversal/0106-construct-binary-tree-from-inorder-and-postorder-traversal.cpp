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

    TreeNode* get(vector<int> &in,vector<int> &po,
    int il,int ih,int pol,int poh,map<int,int> &m){
        if(pol>poh) return NULL;
        if(pol==poh)    return new TreeNode(po[poh]);
        TreeNode* root=new TreeNode(po[poh]);
        int lc=m[po[poh]]-il;
        root->left=get(in,po,il,m[po[poh]]-1,pol,pol+lc-1,m);    
        root->right=get(in,po,m[po[poh]]+1,ih,pol+lc,poh-1,m);
        return root;     
    }

public:
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        map<int,int> m;
        for(int i=0;i<in.size();i++)    m[in[i]]=i;
        return get(in,po,0,in.size()-1,0,in.size()-1,m);
    }
};