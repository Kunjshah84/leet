class Solution {

    int get(vector<int> &nums,int n,int s){
        vector<int> dp(n,-1);
        dp[s]=nums[s];
        dp[s+1]=max(nums[s],nums[s+1]);
        for(int i=s+2;i<n;i++)  dp[i]=max((nums[i]+dp[i-2]),dp[i-1]);
        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        // Tebulation:
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);
        return max(get(nums,nums.size(),1),get(nums,nums.size()-1,0));
    }
};