class Solution {

    int get(vector<vector<int>> &grid,int i,int j1,int j2,
    vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())    return -1e6;
        if(i==grid.size()-1){
            if(j1==j2)  return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)   return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int k=-1;k<2;k++){
            int nj1=j1+k;
            for(int j=-1;j<2;j++){
                int nj2=j2+j;
                if(j1==j2)  maxi=max(maxi,grid[i][j1]+get(grid,i+1,nj1,nj2,dp));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+
                get(grid,i+1,nj1,nj2,dp));
            }
        }
        return dp[i][j1][j2] =maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),
        vector<vector<int>> (grid[0].size(),vector<int> (grid[0].size(),-1)));
        return get(grid,0,0,grid[0].size()-1,dp);
    }
};