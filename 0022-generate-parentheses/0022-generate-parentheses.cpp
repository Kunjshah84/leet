class Solution {

    void get(int limit,vector<string> &ans,string temp,int op,int clo,int ind,int tc){
        if(ind==limit*2){
            if(tc==0)
                ans.push_back(temp);
            return ;
        }
        if(op){
            temp.push_back('(');
            get(limit,ans,temp,op-1,clo,ind+1,tc+1);
            temp.pop_back();
        }
        if(clo>0 && tc>0){
            temp.push_back(')');
            get(limit,ans,temp,op,clo-1,ind+1,tc-1);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        get(n,ans,"(",n-1,n,1,1);
        return ans;
    }
};