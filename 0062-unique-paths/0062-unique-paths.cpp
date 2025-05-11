class Solution {
public:
    int uniquePaths(int i, int j) {
        vector<int> dp(j,1); 
        for(int m=1;m<i;m++){
            int var=0;
            for(int n=0;n<j;n++){
                dp[n]+=var;
                var=dp[n];
            }
        }
        return dp[j-1];
    }
};