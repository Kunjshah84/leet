class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suf=nums;
        for(int i=1;i<nums.size();i++)  nums[i]*=nums[i-1];
        for(int i=nums.size()-2;i>=0;i--)  suf[i]*=suf[i+1];
        for(int i=0;i<nums.size();i++)
            suf[i]=(((!i)?1:nums[i-1])*((i==nums.size()-1)?1:suf[i+1]));
        return suf;
    }
};