class Solution {

    bool get(vector<int> &nums,int target,int sum,int ind,vector<vector<int>> &dp) {
        if(target==(sum-target))    return 1;
        if(target>(sum-target)) return 0;
        if(ind<0)   return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];
        return dp[ind][target]=get(nums,target+nums[ind],sum,ind-1,dp) | get(nums,target,sum,ind-1,dp);
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int> (sum+1,-1));
        return get(nums,0,sum,nums.size()-1,dp);
    }
};