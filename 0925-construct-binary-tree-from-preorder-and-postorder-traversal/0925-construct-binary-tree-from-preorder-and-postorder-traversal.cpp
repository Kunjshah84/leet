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

    TreeNode* get(vector<int> &pre,vector<int> &po,
    int prel,int preh,int pol,int poh,map<int,int> &m){
        if(prel>preh)   return NULL;
        if(prel==preh)  return new TreeNode(pre[prel]);
        TreeNode* root=new TreeNode(pre[prel]);
        int lc=m[po[poh-1]]-prel-1;
        root->left=get(pre,po,prel+1,prel+lc,pol,pol+lc-1,m);
        root->right=get(pre,po,prel+lc+1,preh,pol+lc,poh-1,m);
        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& po) {
        map<int,int> m;
        for(int i=0;i<pre.size();i++)   m[pre[i]]=i;
        return get(pre,po,0,pre.size()-1,0,pre.size()-1,m);
    }
};