#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans={1,2,3,4,5,6,7,8,9};
    int low=0,high=ans.size()-1,targt=7;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(ans[mid]==targt){
            cout<<"Yeee"<<endl;
            break ;
        }
        else if(ans[mid]>targt) high=mid-1;
        else    low=mid+1;
    }
    return 0;
}
