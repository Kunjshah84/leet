class Solution {

    // int get(int i,int j){
    //     if(i<0 || j<0)    return 0;
    //     if(i==0 && j==0)    return 1;
    //     int left=get(i,j-1);
    //     int up=get(i-1,j);
    //     return left+up;
    // }

    int get(int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0)  return 0;
        if(!i && !j)    return 1;
        if(dp[i][j]!=-1)    return dp[i][j];
        return dp[i][j]=get(i,j-1,dp)+get(i-1,j,dp);
    }
public:
    int uniquePaths(int i, int j) {
        vector<vector<int>> dp(i,vector<int> (j,-1));
        return get(i-1,j-1,dp);
    }
};