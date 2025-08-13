class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++)
            for(int j=0;j<matrix.size();j++){
                int left=INT_MAX,down=matrix[i-1][j],right=INT_MAX;
                if((j+1)<matrix.size()) right=matrix[i-1][j+1];
                if((j-1)>=0)    left=matrix[i-1][j-1];
                matrix[i][j]+=min(down,min(right,left));
            }
        int ans=INT_MAX;
        for(auto it:matrix[matrix.size()-1])    ans=min(ans,it);
        return ans;
    }
};