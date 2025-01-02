class Solution {

    bool isVowel(char temp){
        if(temp=='a' || temp=='e' || temp=='i' || temp=='o' || temp=='u')   return 1;
        return 0;
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size(),0);
        vector<int> ans(queries.size(),0);
        prefix[0]= (isVowel(words[0][0]) && isVowel(words[0][words[0].size()-1])) ? 1: 0;
        for(int i=1;i<words.size();i++)
            prefix[i]=(isVowel(words[i][0]) 
            && isVowel(words[i][words[i].size()-1])) ? 
            (prefix[i-1]+1) : prefix[i-1];              
        int cnt=0;
        for(int i=0;i<queries.size();i++)
            if(queries[i][0]==0)    ans[i]+=prefix[queries[i][1]];
            else    ans[i]+=(prefix[queries[i][1]]-prefix[queries[i][0]-1]);   
        return ans;
    }
};