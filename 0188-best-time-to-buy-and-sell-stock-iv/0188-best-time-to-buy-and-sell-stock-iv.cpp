class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (2,vector<int> (k+1)));
        // Base case:
        for(int i=0;i<prices.size();i++)
            dp[i][0][0]=dp[i][1][0]=0;
        int n=prices.size();
        for(int i=0;i<(k+1);i++)
            dp[n][1][i]=dp[n][0][i]=0;
        for(int i=n-1;i>=0;i--){
            for(int liberty=0;liberty<2;liberty++){
                for(int tran=1;tran<=k;tran++){
                    int profit=0;
                    if(liberty)
                        profit=max(dp[i+1][0][tran]-prices[i],
                        dp[i+1][1][tran]);
                    else 
                        profit=max(dp[i+1][1][tran-1]+prices[i],
                        dp[i+1][0][tran]);
                    dp[i][liberty][tran]=profit;
                }
            }
        }
        return dp[0][1][k];
    }
};