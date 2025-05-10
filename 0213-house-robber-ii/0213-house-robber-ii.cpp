class Solution {

    int get(vector<int> &nums,int n,int s){
        int pre1=max(nums[s+1],nums[s]),pre2=nums[s];
        for(int i=s+2;i<n;i++){
            int temp=pre1;
            pre1=max((nums[i]+pre2),pre1);
            pre2=temp;
        }
        return pre1;
    }

public:
    int rob(vector<int>& nums) {
        // Tebulation:
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);
        return max(get(nums,nums.size(),1),get(nums,nums.size()-1,0));
    }
};