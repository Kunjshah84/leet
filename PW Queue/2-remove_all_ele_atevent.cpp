#include<iostream>
#include<queue>
using namespace std;

    void get(queue<int> &t,int cnt){
        if(!cnt)
            return ;
        int te=t.front();
        t.pop();
        get(t,cnt-1);
        if(cnt%2)
            t.push(te);
    }

    void display(queue<int> &q){
        int si=q.size();
        for(int i=1;i<=si;i++){
            cout<<q.front()<<endl;
            int t=q.front();
            q.pop();
            q.push(t);
        }
    }

    void promethod(queue<int> &q){
        cout<<"Zero based indexing:"<<endl;
        int n=q.size();
        for(int i=0;i<n;i++){
            if(i%2==1)
                q.push(q.front());
            q.pop();
        }
    }

int main(){
    queue<int> q;
    cout<<"Hello"<<endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<"Thing using recursion"<<endl;
    get(q,q.size());
    cout<<endl;
    display(q);
    queue<int> f;
    f.push(1);
    f.push(2);
    f.push(3);
    f.push(4);
    f.push(5);
    f.push(6);
    promethod(f);
    display(f);
    return 0;
}