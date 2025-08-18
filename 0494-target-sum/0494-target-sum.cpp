class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int find=totalSum+target;
        if((find%2) || abs(target)>totalSum) return 0;
        find/=2;
        vector<int> dp(find+1,0);
        dp[0]=1;
        for(auto it:nums)
            for(int j=find;j>=it;j--)    
                dp[j] += dp[j-it];
        return dp[find];
    }
};