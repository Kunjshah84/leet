class Solution {

    int get(vector<vector<int>>& matrix,int curr,int m,vector<vector<int>> &dp){
        if(!m)  return matrix[0][curr];
        if(dp[m][curr]!=-100001) return dp[m][curr];
        int s1=get(matrix,curr,m-1,dp),s2=INT_MAX,s3=INT_MAX;
        if((curr+1)<matrix[0].size())   s2=get(matrix,curr+1,m-1,dp);
        if((curr-1)>=0) s3=get(matrix,curr-1,m-1,dp);
        return dp[m][curr]=matrix[m][curr]+min(s1,min(s2,s3));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Reason behind the putting the 100001 is crazy: 
        int var=INT_MAX;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-100001)); 
        for(int i=0;i<n;i++)    var=min(var,get(matrix,i,m-1,dp));
        return var;
    }
};