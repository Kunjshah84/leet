class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int var=INT_MAX;
        int m=triangle.size();
        int n=triangle[triangle.size()-1].size();
        vector<int> dp(n,-1);
        dp[0]=triangle[0][0];
        for(int i=1;i<m;i++){
            vector<int> temp=dp;
            for(int j=0;j<triangle[i].size();j++){
                int fi=INT_MAX,se=INT_MAX;
                if(j<triangle[i-1].size())  fi=dp[j];
                if((j-1)>=0)    se=dp[j-1];
                temp[j]=triangle[i][j]+min(fi,se);
            }
            dp=temp;
        }
        for(auto it:dp)    var=min(var,it);
        return var;
    }
};