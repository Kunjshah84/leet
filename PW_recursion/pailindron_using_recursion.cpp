#include<iostream>
#include<vector>
using namespace std;

    bool get(vector<int> nums,int ind){
        if(ind>(nums.size()/2))
            return true;
        return (nums[ind]==nums[nums.size()-ind-1])? get(nums,ind+1) : false;
    }

int main(){
    vector<int> nums={1,2,1,2};
    cout<<get(nums,0);
    return 0;
}