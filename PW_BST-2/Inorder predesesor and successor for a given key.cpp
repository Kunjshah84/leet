#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }   
};

TreeNode* insert_node(TreeNode* &root,int val){
    if(root==NULL){
        root=new TreeNode(val);
        return root;
    }
    if(root->val>val)   root->left=insert_node(root->left,val);
    else root->right=insert_node(root->right,val);
    return root;
} 

void leveltraversal(TreeNode* root){
    if(!root)   return ;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(!temp){
            cout<<endl;
            if(!q.empty())  q.push(NULL);
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left)  q.push(temp->left);
            if(temp->right)  q.push(temp->right);
        }
    }
}
   
void print_pre_and_succ(TreeNode* root,int val){
    int suc,pre;
    while(root->val!=val){
        if(root->val>val){
            suc=root->val;
            root=root->left;
        }
        else{
            pre=root->val;
            root=root->right;
        }
    }
    TreeNode* left_t=root->left;
    TreeNode* right_t=root->right;
    while(left_t){
        suc=left_t->val;
        left_t=left_t->right;
    }
    while(right_t){
        suc=right_t->val;
        right_t=right_t->left;
    }

    cout<<"The pre and succ is"<<pre<<" "<<suc<<endl; 
}

int main(){
    TreeNode* root=NULL;
    cout<<"Insert the value of root node first:-"<<endl;
    int data;
    cin>>data;
    do{
        insert_node(root,data);
        cin>>data;
    }while(data!=-1);
    cout<<"The level order traversal of the tree is:-"<<endl;
    leveltraversal(root);
    cout<<"Printing the inorder predessesor of the number 10 in the given BST"<<endl;
    print_pre_and_succ(root,10);
    return 0;
}