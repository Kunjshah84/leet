class Solution {

    void BFS(vector<bool> &visited,int ver,vector<vector<int>>& isConnected){
        queue<int> q;
        q.push(ver);
        visited[ver]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<isConnected[curr].size();i++)
                if(i!=curr && isConnected[curr][i] && !visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        vector<bool> visited(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++)
            if(!visited[i]){
                BFS(visited,i,isConnected);
                cnt++;
            }
        return cnt;
    }
};