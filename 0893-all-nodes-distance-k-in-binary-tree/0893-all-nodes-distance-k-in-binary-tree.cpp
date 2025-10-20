/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    void DFS(vector<int> &ans,TreeNode* root,int lev,int k,map<TreeNode*,TreeNode*> &parentMap
    ,map<TreeNode*,bool> &visited){
        if(!root || visited[root])   return ;
        visited[root]=1;
        if(lev==k){
            ans.push_back(root->val);
            return ;
        }
        DFS(ans,parentMap[root],lev+1,k,parentMap,visited);
        if(root->left)  DFS(ans,root->left,lev+1,k,parentMap,visited);
        if(root->right)  DFS(ans,root->right,lev+1,k,parentMap,visited);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parentMap;
        // Doing the BFS for the parent map fillation:
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                parentMap[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parentMap[temp->right]=temp;
                q.push(temp->right);
            }
        }
        map<TreeNode*,bool> visited;
        vector<int> ans;
        DFS(ans,target,0,k,parentMap,visited);
        return ans;
    }
};