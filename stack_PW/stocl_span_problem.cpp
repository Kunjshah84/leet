#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    int arr[]={100,80,60,70,60,75,85};
    int ans[7];
    s.push(0);
    ans[0]=1;
    for(int i=1;i<7;i++){
        while(!s.empty() && arr[s.top()]<=arr[i])
            s.top();
        if(s.empty())   ans[i]=-1;
        else    ans[i]=s.top();
        s.push(i);
    }
    for(int i=0;i<7;i++)
        ans[i]=i-ans[i];
    return 0;
}