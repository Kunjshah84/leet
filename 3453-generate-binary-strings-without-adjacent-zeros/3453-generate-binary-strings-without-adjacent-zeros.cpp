class Solution {

    void get(vector<string> &ans,int n,string temp){
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }
        if(temp.empty() || temp[temp.size()-1]!='0'){
            temp+="0";
            get(ans,n,temp);
            temp.pop_back();
        }
        temp+="1";
        get(ans,n,temp);
    }

public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        get(ans,n,"");
        return ans;
    }
};