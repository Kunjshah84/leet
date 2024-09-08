#include<iostream>
#include<stack>
using namespace std;
int main(){
    cout<<"hyyy"<<endl;
    int arr[10]={22,1,25,11,0,-1,4,6,2,10};
    int arr2[10];
    int n=10;
    arr2[n-1]=-1;
    stack<int> s;
    s.push(arr[n-1]);
    // cout<<"Top element is"<<s.top()<<endl;
    //To solve this type of question of stack we have to use pop() ans and pop() repetedly;
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && arr[i]>s.top())
            s.pop();
        if(s.empty())
            arr2[i]=-1;
        else
            arr2[i]=s.top();
        s.push(arr[i]);
    }
    for(auto it:arr2)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}