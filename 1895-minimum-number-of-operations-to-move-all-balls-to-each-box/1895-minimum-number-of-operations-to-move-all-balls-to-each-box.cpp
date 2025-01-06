class Solution {
public:
    vector<int> minOperations(string str) {
        vector<int> ans;
        for(int i=0;i<str.size();i++){
            int cnt=0;
            int j=0,k=str.size()-1;
            while(j<i){
                if(str[j]=='1') cnt+=(i-j);
                j++;
            }
            while(k>i){ 
                if(str[k]=='1') cnt+=(k-i);
                k--;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};