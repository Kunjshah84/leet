class Solution {

    bool  get(map<string,int> &m,int si,string temp,string &ans,int ind){
        if(ind==si){
            if(!m[temp]){
                ans=temp;
                return 1;
            }
            return 0;
        }
        temp+='0';
        if(get(m,si,temp,ans,ind+1))  return 1;
        temp.pop_back();
        temp+='1';
        if(get(m,si,temp,ans,ind+1))  return 1;
        return 0;
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int> m;
        for(auto it:nums)   m[it]++;
        string ans="";
        get(m,nums[0].size(),"",ans,0); 
        return ans;
    }
};