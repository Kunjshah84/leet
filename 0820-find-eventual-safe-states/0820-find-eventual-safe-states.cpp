class Solution {

    bool dfs(vector<int> &visited,vector<vector<int>> &graph,vector<int> &path,
    vector<int> &cycle,int ver){
        visited[ver]=1;
        path[ver]=1;
        for(auto it:graph[ver]){
            if(!visited[it] && dfs(visited,graph,path,cycle,it))    return 1;
            else if(visited[it] && path[it])   return 1;
        }
        path[ver]=0;
        cycle[ver]=1;
        return 0;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // The another solution is that we have to find 
        // Weather the node is a part of the cycle or the node is 
        // contrebutiong the cycle if yes the can not going to call as the safe
        // Node
        vector<int> visited(graph.size(),0);
        vector<int> path(graph.size(),0);
        vector<int> cycle(graph.size(),0);
        for(int i=0;i<graph.size();i++)
            if(!visited[i]) dfs(visited,graph,path,cycle,i);  
        vector<int> ans;
        for(int i=0;i<graph.size();i++) if(cycle[i])    ans.push_back(i);
        return ans;
    }
};