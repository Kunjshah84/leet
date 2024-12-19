class Solution {
public:
    int maxProfit(vector<int>& p) {
        int tillmin=INT_MAX,ans=0;
        for(int i=0;i<p.size();i++){
            tillmin=min(tillmin,p[i]);
            ans=max(ans,p[i]-tillmin);
        }
        return ans;
    }
};