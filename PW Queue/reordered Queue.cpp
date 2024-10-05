#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
    //Do this question using one stack only:
    //Mix the intervals elements and use only one stack:
    //Initialy we are having one queue:
    // My first target is to get the stack which have the first half of the queue:
    stack<int> s;
    queue<int> q; 
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    // q.push(9);
    int hs=q.size()/2;
    for(int i=0;i<hs;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();  
    }
    for(int i=0;i<hs;i++){
        q.push(q.front());
        q.pop();
    }
    for(int i=0;i<hs;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }   
    //Printing the Queue:
    for(int i=0;i<2*hs;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}