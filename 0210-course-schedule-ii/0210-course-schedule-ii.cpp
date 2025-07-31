class Solution {

    bool dfs(int ver,vector<vector<int>> &list,vector<int> &visited,
    queue<int> &s,vector<int> &path){
        visited[ver]=1;
        path[ver]=1;
        for(auto it:list[ver]){
            if(!visited[it] && dfs(it,list,visited,s,path))  return 1;
            else if(path[it])   return 1;
        }
        path[ver]=0;
        s.push(ver);
        return 0;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(numCourses);
        for(int i=0;i<prerequisites.size();i++) 
            list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        vector<int> visited(list.size(),0);
        vector<int> path(list.size(),0);
        queue<int> s;
        for(int i=0;i<list.size();i++)  
            if(!visited[i] && dfs(i,list,visited,s,path))  return {};
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.front());
            s.pop();
        }
        return ans;
    }
};