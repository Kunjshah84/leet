class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(),1);
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=prev;
            prev*=nums[i];
        }
        prev=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            pre[i]*=prev;
            prev*=nums[i];
        }
        return pre;
    }
};