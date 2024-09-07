#include<iostream>
#include<stack>
using namespace std;

    void push_at_end(stack<int> &s,int ind,int po,int n){
        if(ind==po || s.empty()){
            s.push(n);
            return ;
        }
        int temp=s.top();
        s.pop();
        push_at_end(s,ind+1,po,n);
        s.push(temp);
    }

int main(){
    stack<int> s;
    s.push(6);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    int n,po=1;
    cout<<"Enter the position at wich you have to put the element! and after enter the position also"<<endl;
    cin>>n>>po; 
    push_at_end(s,1,po,n);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}