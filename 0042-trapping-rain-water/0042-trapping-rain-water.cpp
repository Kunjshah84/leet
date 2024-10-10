class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> lm(h.size()),rm(h.size());
        lm[0]=h[0];
        for(int i=1;i<h.size();i++)
            lm[i]=max(h[i],lm[i-1]);
        rm[h.size()-1]=h[h.size()-1];
        for(int i=h.size()-2;i>=0;i--)
            rm[i]=max(h[i],rm[i+1]);
        int ans=0;
        for(int i=1;i<h.size()-1;i++)
            ans+=min(lm[i],rm[i])-h[i];
        return ans;
    }
};