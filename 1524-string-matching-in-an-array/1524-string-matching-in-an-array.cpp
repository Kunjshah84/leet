class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
    });
        for(auto it:words)  cout<<it<<" ";
        cout<<endl;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                int k=0;
                while(k<words[j].size()){
                    if(words[j][k]==words[i][0]){
                        string temp = words[j].substr(k, words[i].size());
                        cout<<temp<<endl;
                        if(words[i]==temp){
                            ans.insert(temp);
                        }
                    }
                    k++;
                }
            }
        }
        vector<string> ve(ans.begin(),ans.end());
        return ve;
    }
};                          