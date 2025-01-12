class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ans(26,0);
        for(char it:s)  ans[it-'a']++;
        for(char it:t)  ans[it-'a']--;
        for(auto it:ans)    if(it)  return 0;
        return 1;
    }
};