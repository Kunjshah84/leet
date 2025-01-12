class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++)
            if(s.substr(i)==goal.substr(0,goal.size()-i) 
            &&  goal.substr(goal.size()-i)==s.substr(0,i))  return 1;
        return 0;
    }
};