class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> list(n);
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> q;
        for(int i=0;i<flights.size();i++)   
            list[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        vector<int> distance(n,1e9);
        distance[src]=0;
        q.push({0,{0,src}});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            if(it.second.second==dst || it.first>k)   continue ;
            int ver=it.second.second;
            int stop=it.first;
            int desti=it.second.first;
            for(auto it:list[ver]){
                if(distance[it.first] > (desti + it.second)){
                    distance[it.first]=desti + it.second;
                    q.push({stop+1,{distance[it.first],it.first}});
                }
            }
        }
        return distance[dst]==1e9 ? -1 : distance[dst];
    }
};