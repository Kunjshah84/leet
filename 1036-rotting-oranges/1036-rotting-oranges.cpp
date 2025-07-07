class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<pair<int,int> , int>> q;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==2)   q.push(make_pair(make_pair(i,j),0));
        while(!q.empty()){
            pair<pair<int,int> , int> temp=q.front();
            q.pop();
            ans=max(ans,temp.second);
            vector<int> r={0,0,+1,-1}; 
            vector<int> c={+1,-1,0,0};
            for(int i=0;i<4;i++){
                int nr=temp.first.first+r[i];
                int nc=temp.first.second+c[i];
                if(!(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size() || 
                grid[nr][nc]==2 || grid[nr][nc]==0)){
                    q.push(make_pair(make_pair(nr,nc),temp.second+1));
                    grid[nr][nc]=2;
                }
            } 
        }
        for(auto it:grid)
            for(auto tit:it)    if(tit==1)  return -1;
        return ans;
    }
};