class Solution {
public:
    string reorganizeString(string s) {
        vector<int> ans(26,0);
        int max_freq=0;
        char max_frchar;
        for(int i=0;i<s.size();i++){
            ans[s[i]-'a']++;
            if(max_freq<ans[s[i]-'a']){
                max_freq=ans[s[i]-'a'];
                max_frchar=char(s[i]);
            }
        } 
        if(max_freq>(s.size()+1)/2) return "";
        vector<char> operation(s.size());
        int ind=0;
        while(ans[max_frchar-'a']){
            operation[ind]=max_frchar;
            ind+=2;
            ans[max_frchar-'a']--;
        }
        for(int i=0;i<26;i++){
            while(ans[i]--){
                if(ind>=operation.size())   ind=1;
                operation[ind]=char('a'+i);
                ind+=2;
            }
        }
        string final_string(operation.begin(),operation.end());
        return final_string;
    }
};