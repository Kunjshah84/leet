class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,1e9); 
        for(int i=0;i<=amount;i++)  
            if(!(i%coins[0])) dp[i]=(i/coins[0]);
        for(int i=1;i<coins.size();i++)
            for(int am=coins[i];am<=amount;am++)    
                dp[am]=min((1+dp[am-coins[i]]),dp[am]);
        return dp[amount]==1e9 ? -1 : dp[amount]; 
    }
};