class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]>=97 && s[i]<=122)    ans+=s[i];
            else ans.pop_back();
        }
        return ans;
    }
};