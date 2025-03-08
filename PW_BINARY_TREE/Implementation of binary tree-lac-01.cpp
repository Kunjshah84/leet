#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

    void displaytree(Node* root){
        if(root==NULL)  return ;
        cout<<root->val<<" ";
        displaytree(root->left);
        displaytree(root->right);
    }

int main(){
    //From this we can only ad
    d the node of the tree with our hand:
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    //Now disply the tree:
    displaytree(a);
    return 0;
}