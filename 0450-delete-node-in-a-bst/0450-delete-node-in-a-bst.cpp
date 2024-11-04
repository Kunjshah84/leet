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
class Solution{
    int get_min(TreeNode* root){
        while(root->left)
            root=root->left;
        return root->val;
    }
    TreeNode* get(TreeNode* root,int val){
        if(!root)   return NULL;
        if(root->val>val){
            root->left=get(root->left,val);
            return root;
        }
        else if(root->val<val){
            root->right=get(root->right,val);
            return root;
        }
        else{
            
            if(!root->right && !root->left){
                TreeNode* temp=root;
                delete temp;
                return NULL;
            }
            else if((!root->left && root->right) || (root->left && !root->right)){
                if(!root->left){
                    TreeNode* temp=root->right;
                    delete root;
                    return temp;
                }
                else{
                    TreeNode* temp=root->left;
                    delete root;
                    return temp;
                }
            }
            else{
                int min_val=get_min(root->right);
                root->val=min_val;
                root->right=get(root->right,min_val);
            }
            return root;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return get(root,key);
    }
};