class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,j=0,var1=0,var2=0;
        while(i<word1.size() && j<word2.size()){
            if(word1[i][var1]!=word2[j][var2])  return 0;
            var1++;
            var2++;
            if(var1>=word1[i].size()){
                var1=0;
                i++;
            }
            if(var2>=word2[j].size()){
                var2=0;
                j++;
            }
        }
        if(i<word1.size() || j<word2.size() || !j || !i)    return 0;
        return 1;
    }
};