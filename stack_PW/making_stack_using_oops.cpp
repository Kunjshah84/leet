#include<iostream>
#include<stack>
using namespace std;

//I am using the array to implement stack:

    class stack{
        int *arr;
        int top;
        int size;
        stack(int size){
            int *arr=new int[size];
            top=-1;
            this->size=size;
        }
        void push(int ele){ 
            if(top==size-1){
                cout<<"Stack is full"<<endl;
                return ;
            }
            arr[++top]=ele;
        }

        void pop(){
            if(top==-1) cout<<"Stack is empty"<<endl;
            else  top--;
        }
        bool isempty(){
            if(top==-1)
                return 1;
            else
                return 0;
        }

        int size(){
            return top+1;
        }

        int top(){
            return arr[top];
        }
    };

int main(){
    
    return 0;
}