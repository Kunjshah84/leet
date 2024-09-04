#include<iostream>
#include<vector>
using namespace std;
void method1(vector<int> nums){
    for(int i=0;i<nums.size()-1;i++){
        for(int temp=i;temp<nums.size();temp++){
            for(int j=i;j<temp;j++)
                cout<<nums[j];
            cout<<endl;
        }
    }
}
void method2(vector<int> nums,vector<int> ans,int ind){
    if(ind==nums.size()){
        for(auto it:ans)
            cout<<it<<" ";
        cout<<endl;
        return ;
    }
    method2(nums,ans,ind+1);
    if(ans.size()==0 || ans[ans.size()-1]==nums[ind-1]){
        ans.push_back(nums[ind]);
        method2(nums,ans,ind+1);
    }
}
int main(){
    vector<int> nums={1,2,3,4,5};
    method1(nums);
    cout<<"method 2"<<endl;
    method2(nums,{},0);
    return 0;
}