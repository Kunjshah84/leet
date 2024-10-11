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

    void get(TreeNode* root,vector<string> &ans,string temp){
        if(!root){
            temp.erase(temp.size()-1);
            temp.erase(temp.size()-1);
            return ;
        }
        get(root->left,ans,temp+to_string(root->val)+"->");
        get(root->right,ans,temp+to_string(root->val)+"->");
        if(!root->right && !root->left) 
            ans.push_back(temp+to_string(root->val));
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        get(root,ans,"");
        return ans;
    }
};