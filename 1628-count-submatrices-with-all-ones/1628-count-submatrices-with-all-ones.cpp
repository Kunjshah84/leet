class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<int> col_cnt(mat[0].size(),0);
        stack<pair<int,pair<int,int>>> s;
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int col=0;col<mat[0].size();col++) 
                if(mat[i][col]) col_cnt[col]++;
                else col_cnt[col]=0;
            s.push({-1,{-1,0}});
            for(int col=0;col<col_cnt.size();col++){
                while(s.top().first >= col_cnt[col])    s.pop();
                int sub_ans=(col-(s.top().second.first))*col_cnt[col];
                sub_ans+=(s.top().second.second);
                ans+=(sub_ans);
                s.push({col_cnt[col],{col,sub_ans}});
            }
            while(s.size()) s.pop();
        }
        return ans;
    }
};