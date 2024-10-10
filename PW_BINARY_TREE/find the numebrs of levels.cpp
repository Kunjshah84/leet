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

    int levels(Node* root){
        if(!root)   return 0;
        return 1+max(levels(root->left),levels(root->right));
    }

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(50);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    cout<<"the total number  of levels in the tree is:-"<<levels(a)<<endl;
    return 0;
}