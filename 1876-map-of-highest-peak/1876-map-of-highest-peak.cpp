class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> ans(isWater.size(),vector<int>(isWater[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<isWater.size();i++)
            for(int j=0;j<isWater[0].size();j++)
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    ans[i][j]=-1;
                }
        while(!q.empty()){
            pair<pair<int,int>,int> temp=q.front();
            q.pop();
            vector<int> r={0,0,+1,-1};
            vector<int> c={+1,-1,0,0};
            for(int i=0;i<4;i++){
                int nr=temp.first.first+r[i];
                int nc=temp.first.second+c[i];
                if(nc>=0 && nr>=0 && nr<isWater.size() && nc<isWater[0].size()
                && !ans[nr][nc]){
                    q.push({{nr,nc},temp.second+1});
                    ans[nr][nc]=temp.second+1;
                }
            }
        }
        for(auto& it:ans)   for(auto& tit:it)   if(tit==-1) tit=0;
        return ans;
    }
};