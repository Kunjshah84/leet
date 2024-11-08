class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())  return 0;
        vector<int> v(150,1000);
        for(int i=0;i<s.size();i++){
            int ind=(int) s[i];
            if(v[ind]==1000)  v[ind]= s[i] - t[i];
            else if(v[ind]!=s[i]-t[i])    return 0;
        }
        for(int i=0;i<v.size();i++) v[i]=1000;
        for(int i=0;i<s.size();i++){
            int ind=(int) t[i];
            if(v[ind]==1000) v[ind]=t[i]-s[i];
            else if(v[ind]!=t[i]-s[i])  return 0;
        }
        return 1;
    }
};