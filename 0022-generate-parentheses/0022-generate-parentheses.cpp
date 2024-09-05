class Solution {

    void get(int n,string temp,int op,int clo,vector<string> &ans){
        if(temp.size()==n*2){
            ans.push_back(temp);
            return;
        }
        if(op<n) get(n,temp+'(',op+1,clo,ans);
        if(clo<op) get(n,temp+')',op,clo+1,ans);
    }

public:
    vector<string> generateParenthesis(int n) {
        //This is the method of PW
        vector<string> ans;
        get(n,"",0,0,ans);
        return ans;
    }
};