class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<int> pre(s.size()+1,0),curr(s.size()+1,0);
        string temp=s;
        reverse(temp.begin(),temp.end());
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=temp.size();j++){
                if(s[i-1]==temp[j-1])   curr[j]=1+pre[j-1];
                else curr[j]=max(curr[j-1],pre[j]);
            }
            pre=curr;
        }
        return curr[s.size()];
    }
};