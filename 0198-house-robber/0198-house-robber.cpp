class Solution {

    int get(vector<int> &nums,vector<int> &dp,int ind){
        if(ind<0)    return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=max((nums[ind]+get(nums,dp,ind-2)),(get(nums,dp,ind-1)));
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return get(nums,dp,nums.size()-1);
    }
};