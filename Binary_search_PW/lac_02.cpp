#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans={};
    int l=0,e=ans.size()-1;
    int target=0;
    while(l<=e){
        int mid=l+(e-l)/2;
        if(ans[mid]==target){
            cout<<ans[mid]<<endl;
            break ;
        }
        else if(ans[mid]<target)    l=mid+1;
        else    e=mid-1;
    }
    //have evu kar ke jo number na madiyo hoi to end ne print karvanu che bhai!
    return 0;
}