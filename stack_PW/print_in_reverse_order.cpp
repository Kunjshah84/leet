#include<iostream>
#include<stack>
using namespace std;

    void reverse(stack<int> s){
        if(s.empty())
            return ;
        int temps=s.top();
        s.pop();
        reverse(s);
        s.push(temps);
        cout<<s.top()<<" ";
    }

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    reverse(s);
    cout<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();    
    }
    return 0;
}