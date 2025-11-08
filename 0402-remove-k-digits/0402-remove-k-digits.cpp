class Solution {
public:
    string removeKdigits(string num, int k) {
        int i=0;
        string temp="";
        while(i<num.size()){
            while(temp.size() && k && (temp.back()-'0')>num[i]-'0'){
                temp.pop_back();
                k--;
            }
            temp+=num[i];
            i++;
        }
        int start=0;
        while(start<temp.size() && temp[start]=='0')    start++;
        temp=temp.substr(start);
        while(temp.size() && k--)  temp.pop_back();
        return (temp.size()) ? temp : "0";
    }
};