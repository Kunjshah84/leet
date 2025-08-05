class Solution {
public:
    int countPaths(int n,vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> list(n);
        for(int i=0;i<roads.size();i++){
            list[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            list[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int mod=int(1e9+7);
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,
        greater<pair<long long ,int>>> q;
        vector<pair<long long int,int>> distance(n,{LLONG_MAX,0});
        q.push({0,0});
        distance[0]={0,1};
        while(!q.empty()){
            int ver=q.top().second;
            long long  desti=q.top().first;
            q.pop();
            // if(desti > distance[ver].first) continue ;
            for(auto it:list[ver]){
                if(distance[it.first].first > (desti + it.second)){
                    distance[it.first]={desti + it.second,distance[ver].second};
                    q.push({distance[it.first].first,it.first});
                }
                else if(distance[it.first].first == desti + it.second){
                    int newPaths=(distance[it.first].second+distance[ver].second)%mod;
                    distance[it.first]={distance[it.first].first,newPaths}; 
                }
            }
        }   
        return distance[n-1].first==1e15 ? -1 : distance[n-1].second;
    }
};