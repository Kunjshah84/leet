class Solution {

    int get(int s,int e,vector<int> nums,int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=target) e=mid-1;
            else    s=mid+1;
        }
        return s;   
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=get(0,nums.size()-1,nums,target);
        int e=get(0,nums.size()-1,nums,target+1)-1;
        if(s<nums.size() && nums[s]==target)    return {s,e};
        return {-1,-1};
    }
};