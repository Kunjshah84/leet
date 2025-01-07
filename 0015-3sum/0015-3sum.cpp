class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(auto it:nums) cout<<it<<" ";
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
               if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp{nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    int temp1=nums[j];
                    int temp2=nums[k];
                    while(nums[j]==temp1 && j<k)    j++;
                    while(nums[k]==temp2 && j<k)    k--;
                } 
                else if(nums[i]+nums[j]+nums[k]>0)  k--;  
                else    j++;
            }
            int temp=nums[i];
            while(nums[i]==temp && i<nums.size()-2) i++;
            i--;
        }
        return ans;
    }
};