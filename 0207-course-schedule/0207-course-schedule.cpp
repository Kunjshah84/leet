class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(numCourses);
        int cnt=0;
        vector<int> m(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            list[prerequisites[i][0]].push_back(prerequisites[i][1]); 
            m[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<m.size();i++) if(!m[i])   q.push(i);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it:list[temp]){
                m[it]--;
                if(!m[it])  q.push(it);
            }
            cnt++;
        }
        return (cnt==m.size()) ? 1 : 0;
    }
};