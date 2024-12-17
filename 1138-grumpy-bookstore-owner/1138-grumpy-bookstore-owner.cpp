class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int k) {
        //apade a question ma loss of satisfaction savthi ochu karvanu che
        //etale apade loss of satisfaction savthi vadhare hoi e ind lavani che:
        int j=-1;
        int closs=0;
        while(++j<k)
            if(g[j])   closs+=c[j]; 
        int maxloss=closs;
        int i=1;
        int maxlossind=0;
        while(j<c.size()){
            closs+=( (c[j]*g[j]) - (c[i-1]*g[i-1]));
            if(closs>maxloss){
                maxloss=closs;
                maxlossind=i;
            }
            i++;
            j++;
        }
        int ans=0;
        for(int i=0;i<c.size();i++){
            if(i==maxlossind){
                while(i<maxlossind+k)
                    ans+=c[i++];
                i--;
            }
            else    ans+=(c[i]*(!g[i]));
        }
        return ans;
    }
};