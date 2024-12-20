class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        unordered_map<int,bool> row;
        unordered_map<int,bool> col;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++)  
                if(!m[i][j]){
                    row[i]=1;
                    col[j]=1;
                }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(row[i] || col[j])    m[i][j]=0;
            }
        }
    }
};