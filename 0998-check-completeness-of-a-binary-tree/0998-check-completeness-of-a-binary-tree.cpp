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
        bool flg=0;
        while(!q.empty()){
            if(flg && q.front())    return 0;
            if(!q.front())  flg=1;
            else{
                TreeNode* temp=q.front();
                ans.push_back(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }
            q.pop();
        }
        return 1;
    }
};