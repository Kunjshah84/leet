class Solution {

    int get(vector<vector<int>> &obstacleGrid,int i,int j,vector<vector<int>> &dp) {
        if(i<0 || j<0 || obstacleGrid[i][j])  return 0;
        if(!i && !j)    return 1;
        if(dp[i][j]!=-1)    return dp[i][j];
        return dp[i][j]=get(obstacleGrid,i,j-1,dp)+get(obstacleGrid,i-1,j,dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return get(obstacleGrid,m-1,n-1,dp);
    }
};