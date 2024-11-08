class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int i=0,j=0;
        while(i<strs[0].size() && j<strs[strs.size()-1].size() 
        && strs[0][i]==strs[strs.size()-1][j]){
            i++;
            j++;
        }
        return strs[0].substr(0,i);
    }
};