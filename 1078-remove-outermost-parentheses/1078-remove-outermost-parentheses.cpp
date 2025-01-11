class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(int i=1;i<s.size();i++){
            if(s[i]=='(')   cnt++;
            else cnt--;
            if(cnt!=-1) ans+=s[i];
            else{
                cnt=0;
                i++;
            } 
        }
        return ans;
    }
};