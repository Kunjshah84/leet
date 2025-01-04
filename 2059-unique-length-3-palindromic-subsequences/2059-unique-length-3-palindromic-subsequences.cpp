class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<int,pair<int,int>> m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end())    m[s[i]].first=i;
            m[s[i]].second=i;
        }
        int ans=0;
        for(auto it:m){
            if(it.second.second-it.second.first>1){
                unordered_set<char> set;
                int start=it.second.first,end=it.second.second;
                for(int i=start+1;i<end;i++)    set.insert(s[i]);
                ans+=set.size();
            }
        } 
        return ans;       
    }
};