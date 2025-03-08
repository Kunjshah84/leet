class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        map<int,int> m1;
        map<int,int> m2;
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            int b=q[i][0];
            int color=q[i][1];
            if(m1.find(b)!=m1.end()){
                int current=m1[b];
                if(m2[current]==1)
                    m2.erase(current);
                else
                    m2[current]--;
                m1[b]=color;
                m2[color]++;
            }
            else{
                m1[b]=color;
                m2[color]++;
            }
            ans.push_back(m2.size());
        }
        return ans;
    }
};