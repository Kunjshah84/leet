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

    TreeNode* get(vector<int> &pre,vector<int> &in,
    int prel,int preh,int inl,int inh,map<int,int> &m){
        if(prel>preh)   return NULL;
        if(preh==prel)  return new TreeNode(pre[prel]);
        TreeNode* root=new TreeNode(pre[prel]);
        int i=m[pre[prel]],lc=i-inl;
        root->left=get(pre,in,prel+1,prel+lc,inl,i-1,m);
        root->right=get(pre,in,prel+lc+1,preh,i+1,inh,m);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in=pre;
        sort(in.begin(),in.end());
        map<int,int> m;
        for(int i=0;i<in.size();i++)    m[in[i]]=i;
        return get(pre,in,0,in.size()-1,0,in.size()-1,m);
    }
};