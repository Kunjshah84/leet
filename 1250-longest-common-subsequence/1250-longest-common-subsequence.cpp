class Solution {

    // int get(string &s1,string &s2,int n1,int n2,vector<vector<int>> &dp){
    //     if(n1<0 || n2<0)    return 0;
    //     if(dp[n1][n2]!=-1)  return dp[n1][n2];
    //     if(s1[n1]==s2[n2])  return dp[n1][n2] = 1 + get(s1,s2,n1-1,n2-1,dp);
    //     return dp[n1][n2] = max(get(s1,s2,n1-1,n2,dp),get(s1,s2,n1,n2-1,dp)); 
    // }

public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> curr(text2.size()+1,0),pre(text2.size()+1,0);
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1])  curr[j]=1+pre[j-1];
                else curr[j]=max(pre[j],curr[j-1]);
            }
            pre=curr;
        }
        return pre[text2.size()];
    }
};