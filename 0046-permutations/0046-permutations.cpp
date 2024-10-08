class Solution {

    void get(vector<int> &nums,vector<vector<int>> &ans,int ind){
        if(ind == nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            get(nums,ans,ind+1);
            swap(nums[ind],nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        get(nums,ans,0);
        return ans;
    }
};