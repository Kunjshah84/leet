class Solution {
public:
    int uniquePaths(int i, int j) {
        // Optimizing more it:
        vector<int> dp(j,1); 
        for(int m=1;m<i;m++)
            for(int n=0;n<j;n++)    if(n>0) dp[n]+=dp[n-1];
        return dp[j-1];
    }
};