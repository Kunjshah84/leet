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
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* f=new Node(4);
    Node* e=new Node(6);
    Node* g=new Node(6);
    Node* h=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    d->left=e;
    c->left=f;
    c->right=g;
    g->left=h;
    displaytree(a);
    return 0;
}