class Solution {
public:
    int myAtoi(string s) {
        if(!s.size())
            return 0;
        int ans=0,index=0;
        while(index < s.size() && s[index]==' ')
            ++index;
        if(index==s.size())
            return 0;
        int sign=(s[index]=='-');
        if(s[index]=='+' || sign)
            ++index;
        while(index<s.size() && isDigit(s[index])){
            if((ans> INT_MAX/10) 
                || (ans==INT_MAX/10 && (s[index]-'0')>7))
                return (sign)?INT_MIN:INT_MAX;
            ans=(ans*10)+(s[index]-'0');
            ++index;
        }
        return (sign)?(-1*ans):ans;
    }

    bool isDigit(char c){
        return c>='0' && c<='9';
    }
};