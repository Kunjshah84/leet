class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                ans+=s[i];
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                    ans+=s[i];
                }
            }
            else    ans+=s[i];
        }
        string fans="";
        stack<int> st2;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]==')'){
                st2.push(ans[i]);
                fans+=ans[i];
            }
            else if(ans[i]=='('){
                if(!st2.empty()){
                    st2.pop();
                    fans+=ans[i];
                }
            }
            else    fans+=ans[i];
        }
        reverse(fans.begin(),fans.end());
        return fans;
    }
};