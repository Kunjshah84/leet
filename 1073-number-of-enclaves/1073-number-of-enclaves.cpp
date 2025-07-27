class Solution {

    void dfs(vector<vector<int>>& grid,int i,int j,vector<int> &r,
    vector<int> &c){
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int nr=i+r[k];
            int nc=j+c[k];
            if(nr>=0 && nc>=0 && nr<grid.size() 
            && nc<grid[0].size() && grid[nr][nc])   
                dfs(grid,nr,nc,r,c);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<int> r={+1,-1,0,0};
        vector<int> c={0,0,+1,-1};
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if((!i || !j || i==grid.size()-1 
                || j==grid[0].size()-1) && grid[i][j])  
                    dfs(grid,i,j,r,c);
        int cnt=0;
        for(auto it:grid)   for(auto tit:it)    if(tit) cnt+=tit;
        return cnt;
    }
};