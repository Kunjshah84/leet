class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        //Now we are going to do the brute force to solve this question:
        // if(inter.size()==1) return inter;
        vector<vector<int>> ans;
        sort(inter.begin(),inter.end());
        for(int i=0;i<inter.size();i++){
            int start=inter[i][0];
            int end=inter[i][1];
            if(!ans.empty()  &&  ans.back()[1]>=end)    continue ;
            for(int j=i+1;j<inter.size();j++){
                if(end>=inter[j][0])    end=max(inter[j][1],end);
                else break ;
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};