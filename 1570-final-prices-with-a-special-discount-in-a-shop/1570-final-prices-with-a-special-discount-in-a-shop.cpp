class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        //We have to applay the logic of next smaller element:
        stack<int> s;
        s.push(p[p.size()-1]);
        for(int i=p.size()-2;i>=0;i--){
            while(!s.empty() && p[i]<s.top())
                s.pop();
            int copy=p[i];
            if(!s.empty())  p[i]-=s.top();
            s.push(copy);
        }
        return p;
    }
};