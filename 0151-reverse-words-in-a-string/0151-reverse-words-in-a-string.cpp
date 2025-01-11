class Solution {
public:
    string reverseWords(string s) {
        stringstream obj(s);
        string temp;
        string ans="";
        while(obj>>temp)    ans=temp+" "+ans;
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};