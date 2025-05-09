class Solution {

public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);
        int var2=nums[0],var1=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int temp=var1;
            var1=max((nums[i]+var2),var1);
            var2=temp;
        }
        return var1;
    }
};