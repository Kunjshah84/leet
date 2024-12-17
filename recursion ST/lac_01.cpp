#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    bool get(int ind,vector<int> ans,int sum,int csum,vector<int> temp){
        if(ind==ans.size()){
            if(csum>sum)    return 0;
            if(sum==csum){
                for(auto it:temp)   cout<<it<<" ";
                return 1;
            }
            return 0;
        }
        temp.push_back(ans[ind]);
        if(get(ind+1,ans,sum,csum+ans[ind],temp))   return 1;
        temp.pop_back();
        if(get(ind+1,ans,sum,csum,temp))    return 1;
        return 0;
    }
    int count(int ind,vector<int> ans,int sum,int csum,vector<int> temp){
        if(csum>sum)    return 0;//It will only work when the -ve was not present over here:
        if(ind==ans.size()) return (sum==csum) ? 1 : 0; 
        temp.push_back(ans[ind]);
        int l=count(ind+1,ans,sum,csum+ans[ind],temp);
        temp.pop_back();
        int r=count(ind+1,ans,sum,csum,temp);
        return l+r;
    }

int main() {
    vector<int> ans={1,2,1};
    int sum=2;
    //Print only one whose sum is sum
    get(0,ans,sum,0,{});
    cout<<endl<<"The number of total count is:->"<<count(0,ans,sum,0,{})<<endl;
    return 0;
}