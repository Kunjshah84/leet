class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> distance=heights;
        for(auto &it:distance)  for(auto &tit:it)   tit=1e9;
        distance[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        vector<int> r={0,1,0,-1};
        vector<int> c={1,0,-1,0}; 
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int oldr=it.second.first;
            int oldc=it.second.second;
            int diff=it.first;
            if(oldr==heights.size()-1 && oldc==heights[0].size()-1) return diff;
            for(int i=0;i<4;i++){
                int nr=oldr+r[i];
                int nc=oldc+c[i];
                if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size()){
                    int hike=abs(heights[nr][nc]-heights[oldr][oldc]);
                    int efforts=max(diff,hike);
                    if(efforts < distance[nr][nc]){
                        distance[nr][nc]=efforts;
                        q.push({efforts,{nr,nc}});
                    }
                }
            }
        }
        return distance[distance.size()-1][distance[0].size()-1];
    }
};