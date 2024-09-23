class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int> temp1(h.size());
        vector<int> temp2(h.size());
        stack<int> s1;
        stack<int> s2;
        //For next smaller element:
        s1.push(h.size()-1);
        temp1[h.size()-1]=h.size();
        for(int i=h.size()-2;i>=0;i--){
            while(!s1.empty() && h[i]<=h[s1.top()])
                s1.pop();
            if(s1.empty())   temp1[i]=h.size();
            else    temp1[i]=s1.top();
            s1.push(i);
        }
        //Fot previous smaller element:
        s2.push(0);
        temp2[0]=-1;
        for(int i=1;i<h.size();i++){
            while(!s2.empty() && h[i]<=h[s2.top()])
                s2.pop();
            if(s2.empty())   temp2[i]=-1;
            else    temp2[i]=s2.top();
            s2.push(i);
        }
        // for(int i=0;i<h.size();i++)
        //     cout<<temp1[i]<<" "<<temp2[i]<<endl;
        // return 0;
        int ans=INT_MIN;
        for(int i=0;i<h.size();i++)
            ans=max(ans,(((temp1[i]-i)*h[i]) + ((i-temp2[i]-1)*h[i])));
        return ans;
    }
};