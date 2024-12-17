#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //Find the smallest missing +ve numebr in the sorted unmbers:
    vector<int> ans={0,1,2,3,4,8,9,12};
    int s=0,e=8;
    int mid=s+(e-s)/2;
    while(s<=e){
        mid=s+(e-s)/2;
        if(mid==ans[mid])   s=mid+1;
        else e=mid-1;   
    }
    if(s==ans.size())   cout<<"No missing +ve numbers"<<endl;
    else    cout<<"your missing +ve number is:-"<<s<<endl;
    return 0;
}