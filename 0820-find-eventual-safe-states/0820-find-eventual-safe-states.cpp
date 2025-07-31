class Solution {

int dfs(int ver,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &support,
    vector<int> &ans){
        visited[ver]=1;
        if(!adj[ver].size()){
            ans.push_back(ver);
            return 1;
        }
        int cnt=0;
        for(auto it:adj[ver]){
            if((!visited[it] && dfs(it,adj,visited,support,ans)) 
            || !support[it]) cnt++;         
        }
        support[ver]-=cnt;
        if(!support[ver])   ans.push_back(ver);
        return (!support[ver]) ? 1 : 0;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<bool> visited(V,0);
        vector<int> support(V);
        for(int i=0;i<V;i++)    support[i]=adj[i].size();
        vector<int> ans;
        for(int i=0;i<V;i++)
            if(!visited[i]) dfs(i,adj,visited,support,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};