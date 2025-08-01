class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // How to solve this using BFS!!
        // We know every time we switch on the BFS from the DFS we have to use the 
        // Topo sort kind of logic in which we push somthing ready on the queue:
        // Now what is ready here?--->The edges which is having the 0 OD::
        // after that we have to go to another edges so change the polarity!
        vector<vector<int>> list(graph.size());
        vector<int> m(graph.size(),0);
        for(int i=0;i<graph.size();i++)
            for(int j=0;j<graph[i].size();j++){
                list[graph[i][j]].push_back(i);
                m[i]++;
            }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<graph.size();i++) if(!m[i])   q.push(i);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it:list[temp]){
                m[it]--;
                if(!m[it])  q.push(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};