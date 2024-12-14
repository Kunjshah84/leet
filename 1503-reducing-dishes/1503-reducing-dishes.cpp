class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        //Do some mathemethical observations:::: 
        sort(s.begin(),s.end());
        if(s[s.size()-1]<=0) return 0;
        vector<int> suf=s;
        for(int i=suf.size()-2;i>=0;i--)    suf[i]+=suf[i+1];
        int ans=0,i=-1;
        while(suf[++i]<0){}
        for(int j=s.size()-1;j>=i;j--)  ans+=(s[j]*(j-i+1));
        return ans;
    }
};