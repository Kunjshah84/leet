class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int i=0;
        while(i<strs[0].size() && strs[0][i]==strs[strs.size()-1][i])   i++;
        return strs[0].substr(0,i);
    }
};