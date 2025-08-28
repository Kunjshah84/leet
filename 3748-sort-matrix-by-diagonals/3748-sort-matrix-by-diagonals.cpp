class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>> m;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                m[i-j].push_back(grid[i][j]);
        for(auto &it:m)
            if(it.first>=0) sort(it.second.begin(),it.second.end());
            else sort(it.second.begin(),it.second.end(),greater<int>());
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=m[i-j].back();
                m[i-j].pop_back();
            }
        return grid;
    }
};