class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int tillsum=0,fans=0;
        sort(s.begin(),s.end(),greater<int>());
        for(auto it:s){
            tillsum+=it;
            if(tillsum<0)    return fans;
            fans+=tillsum;
        }
        return fans;
    }
};