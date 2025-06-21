class Solution {

    bool check(string sub){
        int i=0,j=sub.size()-1;
        while(i<=j){
            if(sub[i]!=sub[j])  return 0;
            i++;
            j--;
        }
        return 1;
    }

    void get(vector<vector<string>> &ans,vector<string> temp,
    string s,string sub,int ind){
        if(ind==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=ind;i<s.size();i++){
            sub+=s[i];
            if(check(sub)){
                temp.push_back(sub);
                get(ans,temp,s,"",i+1);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        get(ans,temp,s,"",0);
        return ans;      
    }
};