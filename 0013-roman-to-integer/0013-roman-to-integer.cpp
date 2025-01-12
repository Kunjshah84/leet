class Solution {
    int get_val(char temp){
        if(temp=='I') return 1;
        else if(temp=='V')  return 5;
        else if(temp=='X')  return 10;
        else if(temp=='L')  return 50;
        else if(temp=='C')  return 100;
        else if(temp=='D')  return 500;
        return 1000;
    }
public:
    int romanToInt(string s) {
        int ans=get_val(s[s.size()-1]);
        for(int i=s.size()-2;i>=0;i--){
            if(get_val(s[i])<get_val(s[i+1]))   ans-=get_val(s[i]);
            else ans+=get_val(s[i]);
        }
        return ans;
    }
};