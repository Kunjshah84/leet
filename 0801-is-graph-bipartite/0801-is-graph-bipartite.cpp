class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(colour[i]==-1){
                queue<int> q;
                q.push(i);
                colour[i]=0;
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    for(auto it:graph[temp]){
                        if(colour[it]==-1){
                            colour[it]=!colour[temp];
                            q.push(it);
                        }
                        else if(colour[it]==colour[temp])   return 0;
                    }
                }
            }
        }
        return 1;
    }
};