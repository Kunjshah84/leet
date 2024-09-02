class Solution {

    void get(vector<int> nums,vector<int> temp,int ind,vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])
                continue ;
            temp.push_back(nums[i]);
            get(nums,temp,i+1,ans);
            temp.pop_back();
        }
    }   

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        get(nums,temp,0,ans);
        return ans;
    }
};