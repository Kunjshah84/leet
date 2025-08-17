class Solution {

    // int get(vector<int> &coins,int ind,int amount,vector<vector<int>> &dp){
    //     if(!amount) return 0;
    //     if(!ind){
    //         if(coins[ind]>amount || amount%coins[ind])    return 1e9;
    //         return amount/coins[ind];
    //     }
    //     if(dp[ind][amount]!=-1) return dp[ind][amount];
    //     int nottake=get(coins,ind-1,amount,dp);
    //     int take=1e9;
    //     if(coins[ind]<=amount)  take=1+ get(coins,ind,amount-coins[ind],dp);
    //     return dp[ind][amount]=min(nottake,take);
    // }

public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0)); 
        // Creating the base cases:
        for(int i=0;i<=amount;i++)  
            if(coins[0]>i || i%coins[0]) dp[0][i]=1e9;
            else dp[0][i]=(i/coins[0]);
        for(int i=1;i<coins.size();i++)
            for(int am=1;am<=amount;am++){
                int nottake=dp[i-1][am];
                int take=1e9;
                if(am>=coins[i])    take= 1 + dp[i][am-coins[i]];
                dp[i][am]=min(take,nottake);
            }
        // int ans=get(coins,coins.size()-1,amount,dp);
        return dp[coins.size()-1][amount]==1e9 ? -1 : dp[coins.size()-1][amount]; 
    }
};