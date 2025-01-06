class Solution {
public:
    vector<int> minOperations(string str) {
        if(str.size()==1)   return {0};
        vector<int> prefix(str.size(),0);
        vector<int> sufix(str.size(),0);
        vector<int> send(str.size(),0);
        int cnt=0,ans=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1') cnt++;
            ans+=cnt;
            prefix[i]=ans;
        }
        cnt=0;
        ans=0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='1') cnt++;
            ans+=cnt;
            sufix[i]=ans;
        }
        send[0]=sufix[1];
        send[send.size()-1]=prefix[prefix.size()-2];
        for(int i=1;i<str.size()-1;i++) send[i]=prefix[i-1]+sufix[i+1];
        return send;
    }
};