class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Reason behind the putting the 100001 is crazy: 
        int var=INT_MAX;
        int m=matrix.size(),n=matrix[0].size();
        vector<int> dp(n,-2); 
        for(int i=0;i<n;i++)    dp[i]=matrix[m-1][i];
        for(int i=m-2;i>=0;i--){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int s1=dp[j],s2=INT_MAX,s3=INT_MAX;
                if((j+1)<n) s2=dp[j+1];
                if((j-1)>=0)    s3=dp[j-1]; 
                temp[j]=matrix[i][j]+min(s1,min(s2,s3));
            }
            dp=temp;
        }
        for(int i=0;i<n;i++)    var=min(var,dp[i]);
        return var;
    }
};