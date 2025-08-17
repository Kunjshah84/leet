class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        dp[0]=0;
        for(auto it:coins)
            for(int am=it;am<=amount;am++)  dp[am]=min(dp[am],(1+dp[am-it]));
        return dp[amount]==1e9 ? -1 : dp[amount];
    }
};