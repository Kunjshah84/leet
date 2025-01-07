class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        if(nums.size()==1)  return nums;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[i][1]<nums[j][0]){
                ans.push_back(nums[i]);
                i=j;
            }
            else if((nums[i][1]>nums[j][0]&&nums[i][1]<nums[j][1])||nums[i][1]==nums[j][0]) 
                nums[i][1]=nums[j][1];
            j++;
        }
        ans.push_back(nums[i]);
        return ans;
    }
};