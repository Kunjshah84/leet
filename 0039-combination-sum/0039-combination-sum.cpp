class Solution {

    bool get(vector<int> nums,int i,int target,vector<int> temp,vector<vector<int>> &ans){
        if(target<0)    return 1;
        if(!target){
            ans.push_back(temp);
            return 1;
        }
        while(i<nums.size()){
            temp.push_back(nums[i]);
            if(get(nums,i,target-nums[i],temp,ans)) break ;
            temp.pop_back();
            i++;
        }
        return 0;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        //Yes we can sort the array because the order does not matter in order to search for the subset of the given array:
        //this method is having the less complexity because 
        //if the current sum is inceresed by the vound then no need to check further:
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        get(nums,0,target,{},ans);
        return ans;
    }
};