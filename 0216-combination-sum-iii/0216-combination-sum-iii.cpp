class Solution {

    void get(int index,int limit,int sum,vector<int> temp,vector<vector<int>> &ans){
        if(sum==0 && temp.size()==limit){
            ans.push_back(temp);
            return ;
        }
        if(index>9 || temp.size()>limit || sum<0)
            return ;
        temp.push_back(index);
        get(index+1,limit,sum-index,temp,ans);
        temp.pop_back();
        get(index+1,limit,sum,temp,ans);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        get(1,k,n,{},ans);
        return ans;
    }
};