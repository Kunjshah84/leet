class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0,buy=0;
        for(int i=prices.size()-1;i>=0;i--){
            int var1=max(sell-prices[i] , buy);
            int var2=max(prices[i]+buy,sell);
            buy=var1;
            sell=var2;
        }
        return buy;
    }
};