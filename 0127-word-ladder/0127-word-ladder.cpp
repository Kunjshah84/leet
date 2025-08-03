class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> s(wordList.begin(),wordList.end());
        while(!q.empty()){
            pair<string,int> temp=q.front();
            string main_str=temp.first;
            int old=temp.second;
            q.pop();
            for(int i=0;i<main_str.size();i++){
                string copy=main_str;
                for(int j=0;j<26;j++){
                    copy[i]=j+'a';
                    if(s.find(copy)!=s.end()){
                        if(copy==endWord)   return old+1;
                        q.push({copy,old+1});
                        s.erase(copy);
                    }
                }
            }
        }
        return 0;
    }
};