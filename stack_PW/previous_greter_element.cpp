#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={1,3,2,10,-1,8,9,3,12,2};
    int arr2[10];
    arr2[0]=-1;
    stack<int> s;
    s.push(arr[0]);
    for(int i=1;i<10;i++){
        while(!s.empty() && s.top()<=arr[i])
            s.pop();
        if(s.empty())   arr2[i]=-1;
        else    arr2[s.top()];
        s.push(arr[i]);
    }
    return 0;
}