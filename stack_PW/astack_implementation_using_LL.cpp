#include<iostream>
using namespace std;

//All the operation should be follow the time complexity of stack;

class node{
    public:
    int data;
    node* next;
    node* head=NULL;
    int lock;
    int ind;
    node(int val){
        this->data=val;
        this->next=NULL;
        this->lock=lock;
        this->ind=0;
    }

    void size_fix(int lock){
        this->lock=lock;
    }

    void push(int val){
        if(ind==lock){
            cout<<"Stack is full my brother:"<<endl;
            return ;
        }
        node* newnode=new node(val);
        newnode->next=head;
        head=newnode;
        ind++;
    }

    void pop(){
        if(lock==0){
            cout<<"bhai empty che"<<endl;
            return ;
        }
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    int top(){
        if(lock==0){
            cout<<"bhai empty che"<<endl;
            return ;
        }
        return head->data;
    }
    
};

int main(){

    return ;
}