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

    int maxv(Node* root){
        if(root==NULL)  return -1;
        return max(root->val,max(maxv(root->left),maxv(root->right)));
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
    cout<<"the max value of the tree is:-"<<maxv(a)<<endl;
    return 0;
}