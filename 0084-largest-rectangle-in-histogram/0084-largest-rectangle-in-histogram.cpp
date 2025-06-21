class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> s;
        s.push(0);
        int ans=0;
        for(int i=1;i<=nums.size();i++){
            while(!s.empty() && (i==nums.size() || nums[s.top()]>=nums[i])){
                int temp=nums[s.top()];
                s.pop();
                int comp;
                if(s.empty())  comp=((temp)*(i));
                else    comp=((temp)*(i-s.top()-1));
                ans=max(ans,comp);
            }
            s.push(i);
        }
        return ans;
    }
};