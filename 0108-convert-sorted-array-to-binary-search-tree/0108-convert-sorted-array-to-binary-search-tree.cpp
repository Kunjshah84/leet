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

    TreeNode* get(vector<int> &nums,int s,int e){
        if(s>e) return NULL;
        if(s==e)    return new TreeNode(nums[s]);
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=get(nums,s,mid-1);
        root->right=get(nums,mid+1,e);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return get(nums,0,nums.size()-1);
    }
};