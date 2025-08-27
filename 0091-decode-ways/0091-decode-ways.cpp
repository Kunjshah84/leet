class Solution {
public:

    bool check(string &digits,int ind) {
        string temp=digits.substr(ind,2);
        if(stoi(temp)>26)   return 0;
        return 1;
    }
    
    int get(string& digits,int ind,vector<int> &dp){
        if(ind>=digits.size())  return 1;
        if(ind==digits.size()-1)    return digits[ind]!='0';
        if(dp[ind]!=-1) return dp[ind];
        int leftcnt=0;
        int rightcnt=0;
        if(digits[ind]!='0'){
            leftcnt=get(digits,ind+1,dp);
            if(check(digits,ind)) 
                rightcnt=get(digits,ind+2,dp);
        }
        return dp[ind]=leftcnt+rightcnt;
    }    

    int numDecodings(string digits) {
        vector<int> dp(digits.size(),-1);
        return get(digits,0,dp);
    }
};