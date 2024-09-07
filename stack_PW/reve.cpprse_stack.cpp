#include<iostream>
#include<stack>
using namespace std;

    void push_at_bottom(stack<int> &s,int ele){
        if(s.empty()){
            s.push(ele);
            return ;
        }
        int temp=s.top();
        s.pop();
        push_at_bottom(s,ele);
        s.push(temp);
    }

    void reverse(stack<int> &s){
        if(s.size()==1)
            return ;
        int temp=s.top();
        s.pop();
        reverse(s);
        push_at_bottom(s,temp);
    }

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    stack<int> copy=s;
    cout<<"HELLOW coders"<<endl;
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl<<"Previous stack is"<<endl;
    while(!copy.empty()){
        cout<<copy.top()<<" ";
        copy.pop();
    }
    return 0;
}