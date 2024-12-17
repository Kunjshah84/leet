class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=3)
            if(nums[i]^nums[i-1])   return nums[i-1];
        return nums[nums.size()-1];
        //It will take the time complexity of the O(n/3+nlog(n)):
    }
};