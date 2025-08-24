class Solution {

    int get(vector<int> &prices,int ind,int liberty,vector<vector<int>> &dp){
        if(ind>=prices.size())  return 0;
        if(dp[ind][liberty]!=-1)    return dp[ind][liberty];
        if(liberty) 
            dp[ind][liberty]=max((get(prices,ind+1,0,dp)-prices[ind]),
            get(prices,ind+1,1,dp));
        else    
            dp[ind][liberty]=max(get(prices,ind+2,1,dp)+prices[ind],
            get(prices,ind+1,0,dp));
        return dp[ind][liberty];
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return get(prices,0,1,dp);
    }
};