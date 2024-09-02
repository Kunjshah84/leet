class Solution {

    void get(vector<int> nums,int ind,vector<vector<int>> &ans,bool flag,vector<int> temp){
        if(ind==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[ind]);
        if(ind==nums.size()-1){
            if(flag) get(nums,ind+1,ans,1,temp);
            temp.pop_back();
            get(nums,ind+1,ans,1,temp);
            return ;
        }   
        if(nums[ind]==nums[ind+1]){
            if(flag) get(nums,ind+1,ans,1,temp);
            temp.pop_back();
            get(nums,ind+1,ans,0,temp);
        }
        else{
            if(flag) get(nums,ind+1,ans,1,temp);
            temp.pop_back();
            get(nums,ind+1,ans,1,temp);
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //In the different method without using the for loop!
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        get(nums,0,ans,1,{});
        return ans;
    }
};