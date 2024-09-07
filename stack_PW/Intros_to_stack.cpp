#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    //We can peform total 4 operation on stack:
    //1.push()   2.pop()   3.top()   4.empty() 5.size()
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    //We can print the element of the array in both the way:::
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    //It will never run because the stack is going to empty that is not like of arraay that we print the array and the array will empty;
    while(s.size()>0){
        cout<<s.top()<<endl;
        s.pop();
    }
    //How to get the element in the stack:
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    stack<int> temp;
    while(s.size()>0){
        temp.push(s.top());
        cout<<s.top()<<endl;
        s.pop();
    }
    //when we copy the stack from one stack to another then is will push in the reverse order:
    //Now we have to copy the elment of the temp into the s stack in reverse order
    
}