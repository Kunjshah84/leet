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

    int sizeo(Node* root){
        if(root==NULL)  return 0;
        return 1+sizeo(root->left)+sizeo(root->right);
    }

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    cout<<"Yhe size of the tree is:-"<<sizeo(a)<<endl;
    return 0;
}