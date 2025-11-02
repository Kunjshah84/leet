class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> pse(nums.size(),-1);
        vector<int> nse(nums.size(),n);
        vector<int> nge(nums.size(),n);
        vector<int> pge(nums.size(),-1);
        stack<int> s_pse;
        stack<int> s_pge;
        stack<int> s_nse;
        stack<int> s_nge;
        for(int i=0;i<n;i++){
            // Previous:
            while(s_pge.size() && nums[s_pge.top()]<nums[i])    s_pge.pop();
            if(s_pge.size())    pge[i]=s_pge.top();
            s_pge.push(i);
            while(s_pse.size() && nums[s_pse.top()]>nums[i]) s_pse.pop();
            if(s_pse.size())    pse[i]=s_pse.top();
            s_pse.push(i);
            // Next
            int ind=n-i-1;
            while(s_nge.size() && nums[s_nge.top()]<=nums[ind]) s_nge.pop();
            if(s_nge.size())    nge[ind]=s_nge.top();
            s_nge.push(ind);
            while(s_nse.size() && nums[s_nse.top()]>=nums[ind])  s_nse.pop();
            if(s_nse.size()) nse[ind]=s_nse.top();
            s_nse.push(ind);
        }
        long long sumationLarge=0ll,sumationSmall=0ll;
        for(int i=0;i<n;i++){
            sumationLarge+=(((nge[i]-i)*(i-pge[i])*1ll)*nums[i]*1ll);
            sumationSmall+=(((nse[i]-i)*(i-pse[i])*1ll)*nums[i]*1ll);
        }
        return sumationLarge-sumationSmall;
    }
};