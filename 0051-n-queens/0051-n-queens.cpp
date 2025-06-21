class Solution {

    bool check(vector<string> &temp,int q,int i){
        for(int m=q-1,n=i-1;n>=0 && m>=0;m--,n--)
            if(temp[m][n]=='Q') return 0;
        for(int m=q-1,n=i+1;i<temp.size() && m>=0;m--,n++)
            if(temp[m][n]=='Q') return 0;
        return 1;
    }

    void get(vector<vector<string>> &ans,vector<string> &temp,
    int q,map<int,int> &col){
        if(q==temp.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<temp.size();i++){
            if(col[i]==0 && check(temp,q,i)){
                temp[q][i]='Q';
                col[i]++;
                get(ans,temp,q+1,col);
                temp[q][i]='.';
                col[i]--;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string stemp(n,'.');
        vector<string> temp(n,stemp);
        vector<vector<string>> ans;
        map<int,int> col;
        get(ans,temp,0,col);
        return ans;
    }
};