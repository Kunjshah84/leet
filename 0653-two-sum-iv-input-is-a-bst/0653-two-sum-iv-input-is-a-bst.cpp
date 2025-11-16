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

class TreeIterator{
    public:
    stack<TreeNode*> s;
    bool rev;
    TreeIterator(TreeNode* root,bool rev){
        this->rev=rev;
        pushNodes(root);
    }

    int next(){
        TreeNode* temp=s.top();
        s.pop();
        if(rev)    pushNodes(temp->left);
        else pushNodes(temp->right);
        return temp->val;
    }

    bool hasNext(){
        return s.size();
    }

    void pushNodes(TreeNode* root){
        while(root){
            s.push(root);
            if(rev) root=root->right;
            else root=root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)   return 0;
        TreeIterator* it1=new TreeIterator(root,0);
        TreeIterator* it2=new TreeIterator(root,1);
        int l=it1->next(),r=it2->next();
        while(l<r){
            if((l+r)==k)  return 1;
            else if(l+r<k)  l=it1->next();
            else r=it2->next();
        }
        return 0;
    }
};