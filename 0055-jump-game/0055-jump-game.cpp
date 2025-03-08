class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<i)   return 0;
            sum=max(sum,nums[i]+i);
        }
        return 1;
    }
};