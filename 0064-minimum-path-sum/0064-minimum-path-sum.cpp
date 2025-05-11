class Solution {

    int get(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(!i && !j)    return grid[i][j];
        if(dp[i][j]!=-1)  return dp[i][j];
        int sum1=INT_MAX,sum2=INT_MAX;
        if(j)   sum1=get(grid,i,j-1,dp);
        if(i)   sum2=get(grid,i-1,j,dp);
        return dp[i][j]=grid[i][j]+min(sum1,sum2);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return get(grid,m-1,n-1,dp);
    }
};