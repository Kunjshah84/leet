class Solution {

    bool check(vector<string> &temp,int q,int i){
        for(int m=q-1,n=i-1;m>=0 && n>=0;m--,n--)   
            if(temp[m][n]=='Q')     return 0;
        for(int m=q-1,n=i+1;i<temp.size() && m>=0;m--,n++)  
            if(temp[m][n]=='Q')     return 0;
        return 1;
    }

    int get(int q,vector<string> &temp,map<int,int> &col){
        if(q==temp.size())  return 1;
        int sum=0;
        for(int i=0;i<temp.size();i++){
            if(col[i]==0 && check(temp,q,i)){
                col[i]++;
                temp[q][i]='Q';
                sum+=(get(q+1,temp,col));
                col[i]--;
                temp[q][i]='.';
            }
        }
        return sum;
    }

public:
    int totalNQueens(int n) {
        string subtemp(n,'.');
        vector<string> temp(n,subtemp);
        map<int,int> col;
        return get(0,temp,col);
    }
};