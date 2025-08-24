class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,-1));
        for(int i=n;i<n+2;i++)
            dp[i][0]=dp[i][1]=0;
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<2;j++){
                if(j)   dp[i][j]=max((dp[i+1][0]-prices[i]),dp[i+1][1]);
                else    dp[i][j]=max(dp[i+2][1]+prices[i],dp[i+1][0]);
            }
        return dp[0][1];
    }
};