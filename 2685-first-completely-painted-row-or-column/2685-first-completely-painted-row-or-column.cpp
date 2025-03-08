class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<pair<int,int>> m(((mat.size()*mat[0].size())+1));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                m[mat[i][j]]={i,j};
            }
        }
        vector<int> row(mat.size(),0);
        vector<int> col(mat[0].size(),0);
        for(int it=0;it<arr.size();it++){
            row[m[arr[it]].first]++;
            col[m[arr[it]].second]++;
            if(row[m[arr[it]].first]==mat[0].size() || col[m[arr[it]].second]==mat.size())
                return it;
        }
        return -1;
    }
};