class Solution {

    int get(vector<vector<int>> &triangle,int curr,int row,vector<vector<int>> &dp) {
        if(!row)    return triangle[0][0];
        if(curr>=triangle[row].size())
            return INT_MAX;
        if(dp[row][curr]!=-1)   return dp[row][curr];
        int s1=get(triangle,curr,row-1,dp);
        int s2=get(triangle,curr-1,row-1,dp);
        return dp[row][curr]=(triangle[row][curr]+min(s1,s2));
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int var=INT_MAX;
        int m=triangle.size();
        int n=triangle[triangle.size()-1].size();
        vector<vector<int>> dp(m ,vector<int> (n,-1));
        for(int i=0;i<n;i++)    var=min(var,get(triangle,i,m-1,dp));
        return var;
    }
};