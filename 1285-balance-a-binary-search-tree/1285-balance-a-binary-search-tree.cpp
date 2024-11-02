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
    vector<int> in;
    void get(TreeNode* root,vector<int> &ans){
        if(!root)   return ;
        get(root->left,ans);
        ans.push_back(root->val);
        get(root->right,ans);
    }

    TreeNode* make(vector<int> &nums,int s,int e){
        if(s>e || s==e) return s>e ? NULL : new TreeNode(nums[s]); 
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=make(nums,s,mid-1);
        root->right=make(nums,mid+1,e);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        get(root,in);
        return make(in,0,in.size()-1);
    }
};