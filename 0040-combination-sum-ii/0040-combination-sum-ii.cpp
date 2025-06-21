class Solution {

    void get(int index,int t,vector<vector<int>> &ans,vector<int> c,vector<int> temp){
        if(t==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<c.size();i++){
            if(i>index && c[i]==c[i-1])
                continue ;
            if(c[i]>t)
                break ;
            temp.push_back(c[i]);
            get(i+1,t-c[i],ans,c,temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<int> temp;
        vector<vector<int>> ans;
        get(0,t,ans,c,temp);
        return ans;
    }
};