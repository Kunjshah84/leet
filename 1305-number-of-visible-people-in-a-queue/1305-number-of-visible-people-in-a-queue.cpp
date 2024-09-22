class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans(heights.size(),0);
        stack<int> s;
        s.push(heights.size()-1);
        ans[heights.size()-1]=0;
        for(int i=heights.size()-2;i>=0;i--){
            int temp=0;
            while(!s.empty() && heights[i]>heights[s.top()]){
                s.pop();
                temp++;
            }
            cout<<temp<<endl;
            if(s.empty())   ans[i]=temp;
            else    ans[i]=temp+1;
            s.push(i);
        }
        return ans;
    }
};