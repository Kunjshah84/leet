class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())   return "";
        string temp=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0,k=0;
            while(j<temp.size() && k<strs[i].size() && temp[j]==strs[i][k]){
                j++;
                k++;
            }
            temp=temp.substr(0,j);
        }
        return temp;
    }
};