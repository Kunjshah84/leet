class Solution {
public:
    int uniquePaths(int i, int j) {
        vector<vector<int>> dp(i,vector<int> (j,-1));
        dp[0][0]=1;
        for(int m=0;m<i;m++){
            for(int n=0;n<j;n++){
                if(m || n){
                    int left;
                    int up;
                    if(!m)  up=0;
                    else up=dp[m-1][n];
                    if(!n)  left=0;
                    else left=dp[m][n-1];
                    dp[m][n]=up+left;  
                }
            }
        }
        return dp[i-1][j-1];
    }
};