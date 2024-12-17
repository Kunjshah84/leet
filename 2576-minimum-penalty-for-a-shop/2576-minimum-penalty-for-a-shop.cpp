class Solution {
public:
    int bestClosingTime(string c) {
        vector<int> pre(c.size()+1,0);
        vector<int> suf(c.size()+1,0);
        int var=(c[0]=='N') ? 1 : 0;
        for(int i=1;i<c.size();i++){
            pre[i]=var;
            var=(c[i]=='N') ? var+1 : var;
        }
        pre[pre.size()-1]=var;
        suf[suf.size()-2]= (c[c.size()-1]=='Y') ? 1 : 0;
        for(int i=c.size()-2;i>=0;i--)  suf[i]=suf[i+1]+((c[i]=='Y') ? 1: 0);
        int minvar=INT_MAX,ind;
        for(int i=0;i<=c.size();i++)
            if(pre[i]+suf[i]<minvar){
                minvar=pre[i]+suf[i];
                ind=i;
            } 
        return ind;
    }
};