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
    bool isCompleteTree(TreeNode* root) {
        vector<int> ans; 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            if(!q.front())   ans.push_back(-1);
            else{
                TreeNode* temp=q.front();
                ans.push_back(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }
            q.pop();
        }
        bool flg=0;
        for(auto it:ans){
            if(it==-1)  flg=1;
            if(flg && it!=-1)   return 0;
        }
        return 1;
    }
};