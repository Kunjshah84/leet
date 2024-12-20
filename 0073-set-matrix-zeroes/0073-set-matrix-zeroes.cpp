class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int col=1;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(!m[i][j]){
                    if(!j)
                        col=0;
                    else m[0][j]=0;
                    m[i][0]=0;
                }
            }
        }
        //pahela andar nu karo bhai
        for(int i=1;i<m.size();i++){
            for(int j=1;j<m[i].size();j++){
                if(m[0][j]==0 || m[i][0]==0)    m[i][j]=0;
            }
        }
        if(m[0][0]==0)
            for(int i=1;i<m[0].size();i++)  m[0][i]=0;
        if(col==0)
            for(int i=0;i<m.size();i++) m[i][0]=0;
    }
};