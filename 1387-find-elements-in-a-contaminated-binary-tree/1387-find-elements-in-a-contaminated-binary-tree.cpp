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
class FindElements {
    unordered_set<int> s;
    void get(TreeNode* root,int cnt){
        if(!root)   return ;
        root->val=cnt;
        s.insert(cnt);
        get(root->left,(cnt*2+1));
        get(root->right,(cnt*2+2));
    }
public:
    FindElements(TreeNode* root) {
        int cnt=0;
        get(root,cnt);
    }
    
    bool find(int target) {
        return (s.find(target)==s.end()) ? 0:1; 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */