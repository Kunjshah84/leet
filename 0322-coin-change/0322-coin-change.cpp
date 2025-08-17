class Solution {

    int get(vector<int> &coins,int ind,int amount,vector<vector<int>> &dp){
        if(!amount) return 0;
        if(!ind){
            if(coins[ind]>amount || amount%coins[ind])    return 1e9;
            return amount/coins[ind];
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nottake=get(coins,ind-1,amount,dp);
        int take=INT_MAX;
        if(coins[ind]<=amount)  take=1+ get(coins,ind,amount-coins[ind],dp);
        return dp[ind][amount]=min(nottake,take);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1)); 
        int ans=get(coins,coins.size()-1,amount,dp);
        return ans==1e9 ? -1 : ans; 
    }
};