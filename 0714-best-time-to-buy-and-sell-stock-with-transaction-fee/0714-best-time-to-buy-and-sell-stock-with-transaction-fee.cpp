class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int v1=0,v2=0;
        for(int i=n-1;i>=0;i--){
            int t1=max(v2-prices[i],v1);
            int t2=max(v1+prices[i]-fee,v2);
            v1=t1;
            v2=t2;
        }
        return v1;
    }
};