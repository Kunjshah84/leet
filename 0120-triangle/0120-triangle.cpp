class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int var=INT_MAX;
        int m=triangle.size();
        int n=triangle[triangle.size()-1].size();
        vector<vector<int>> dp(m ,vector<int> (n,-1));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;i++){
            for(int j=0;j<triangle[i].size();j++){
                int fi=INT_MAX,se=INT_MAX;
                if(j<triangle[i-1].size())  fi=dp[i-1][j];
                if((j-1)>=0)    se=dp[i-1][j-1];
                dp[i][j]=triangle[i][j]+min(fi,se);
            }
        }
        for(auto it:dp[dp.size()-1])    var=min(var,it);
        return var;
    }
};