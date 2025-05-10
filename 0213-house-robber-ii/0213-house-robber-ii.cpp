class Solution {

    int get(vector<int> &nums,int ind,int n,vector<int> &dp){
        if(ind<n)   return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=max((nums[ind]+get(nums,ind-2,n,dp)),get(nums,ind-1,n,dp));
    }

public:
    int rob(vector<int>& nums) {
        // Just need to do the task for the two times:  
        // Memoization tech
        if(nums.size()==1)  return nums[0];
        vector<int> dp(nums.size(),-1);
        int temp1=get(nums,nums.size()-1,1,dp);
        dp.assign(nums.size(),-1);
        int temp2=get(nums,nums.size()-2,0,dp);
        return max(temp1,temp2);
    }
};