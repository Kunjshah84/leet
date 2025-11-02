class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int j=0;
        vector<int> temp(asteroids.size(),INT_MIN);
        while(j<asteroids.size() && asteroids[j]<0){
            temp[j]=0;
            j++;
        }
        if(j<temp.size()) s.push(j);
        for(int i=j+1;i<asteroids.size();i++){
            if(asteroids[i]>0){
                s.push(i);
                continue ;
            }
            int val=(-1*asteroids[i]);
            while(s.size() && val>asteroids[s.top()])   s.pop();
            if(!s.size())   temp[i]=0;
            else if(asteroids[s.top()]==val)   s.pop();
        }
        while(s.size()){
            temp[s.top()]=0;
            s.pop();
        }
        vector<int> ans;
        for(int i=0;i<temp.size();i++)
            if(temp[i]!=INT_MIN)    ans.push_back(asteroids[i]);
        return ans;
    }
};