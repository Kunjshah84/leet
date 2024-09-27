//Basics of Queue:

//1-->It follows the FIFO rule:
//2-->We have to do the push and pop peration on the opposite side:

//We push the element from rear and pop from front:
//We are having the front() function instead of top() function/:
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int> &q){
    int si=q.size();
    for(int i=1;i<=si;i++){
        cout<<q.front()<<endl;
        int t=q.front();
        q.pop();
        q.push(t);
    }
}

void revdisplay(queue<int> q){
    if(!q.size())
        return  ;
    int t=q.front();
    q.pop();
    revdisplay(q);
    cout<<t<<endl;
    q.push(t);
}

void revQ_usingstack(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q;
    //Push
    //Pop
    //front-->top
    //back
    //Empty/size:
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    // q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;

    cout<<"display queue"<<endl;
    display(q);//Thre is no need to extra O(n) space to print the Queue like stack:(We can do that in O(n) time complexity:)
    cout<<"display reverse queue"<<endl;
    revdisplay(q);
    cout<<"display queue"<<endl;
    display(q);
    //Now We have to reverse the Q not just print the Q into revese order:
    revQ_usingstack(q);
    //We are not able to do reverse the queue by using queue:
    display(q);
    return 0;
}
