
//Do this after reading the theories:

#include<iostream>
using namespace std;
//We are going to do the BFS and DFS in this code:
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        Node* left=NULL;
        Node* right=NULL;
    }
};

//This is the normal disply method for the BT:

void display(Node* temp){
    if(!temp)   return ;
    cout<<temp->val<<" ";
    display(temp->left);
    display(temp->right);
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
    display(a);
    return 0;
} 