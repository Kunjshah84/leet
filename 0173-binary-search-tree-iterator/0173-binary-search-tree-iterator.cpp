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
class BSTIterator {
    stack<TreeNode*> s;
public:

    void pushNodes(TreeNode* root){
        for(;root;s.push(root),root=root->left);
    }

    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    
    int next() {
        TreeNode* temp=s.top();
        s.pop();
        pushNodes(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return s.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */