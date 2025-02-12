class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        sort(nums.begin(),nums.end());
        if(nums[0]!=0 && nums.size()>=1)
            return 0; 
        while(i<nums.size()-1)
        {
            if(nums[i+1]-nums[i]!=1)
                return (nums[i+1]-1);
            i++;
        }
        return nums.size();
    }
};