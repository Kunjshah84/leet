class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[n-1][m-1] || grid[0][0])  return -1;
        if(grid.size()==1 && grid[0].size()==1) return 1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        grid[0][0]=1;
        vector<int> r={-1,-1,-1,0,0,1,1,1};
        vector<int> c={-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            for(int i=0;i<8;i++){
                int nr=it.first.first+r[i];
                int nc=it.first.second+c[i];
                if(nr==n-1 && nc==m-1)  return it.second+1;
                if(nr>=0 && nc>=0 && nr<n && nc<m && !grid[nr][nc]){
                    q.push({{nr,nc},it.second+1});
                    grid[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};