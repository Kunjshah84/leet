class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> ma;
        unordered_map<int,int> mb;
        vector<int> ans(a.size(),0);
        int cnt=0;
        for(int i=0;i<a.size();i++){
            ma[a[i]]++;
            mb[b[i]]++;
            if(mb.find(a[i])!=mb.end()) cnt++;
            if(ma.find(b[i])!=ma.end())    cnt++;
            if(a[i]==b[i])  cnt--;
            ans[i]=cnt;
        }
        return ans;
    }
};