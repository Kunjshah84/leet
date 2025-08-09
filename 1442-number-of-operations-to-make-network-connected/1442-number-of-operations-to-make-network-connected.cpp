class Solution {

    void dfs(int ver,vector<bool> &visited,vector<vector<int>> &list,
    int &ed_cnt,int &node_cnt){
        visited[ver]=1;
        node_cnt++;
        for(auto it:list[ver]){
            ed_cnt++;
            if(!visited[it])    dfs(it,visited,list,ed_cnt,node_cnt);
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int components_cnt=0;
        // Making the list:
        vector<vector<int>> list(n);
        vector<bool> visited(n,0);
        int extra_edges=0;
        for(int i=0;i<connections.size();i++){
            list[connections[i][0]].push_back(connections[i][1]);
            list[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int edges_cnt=0;
                int node_cnt=0;
                dfs(i,visited,list,edges_cnt,node_cnt);
                components_cnt++;
                edges_cnt/=2;
                // Calculating the extra edges:--->
                if((edges_cnt+1)>node_cnt)
                    extra_edges+=(edges_cnt-(node_cnt-1));
            }
        }
        components_cnt;
        return ((components_cnt-1)>extra_edges) ? -1 : (components_cnt-1);
    }
};