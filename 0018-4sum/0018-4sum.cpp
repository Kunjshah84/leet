class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //Now we are going to remove hte extra space into the previous solution
        if(nums.size()<4)   return {};
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                int s=j+1,e=nums.size()-1;
                while(s<e){
                    long long int sum=(long long int)nums[i]+(long long int)nums[j]+(long long int)nums[s]+(long long int)nums[e];
                    if(sum==(long long int)target){
                        vector<int> temp={nums[i],nums[j],nums[s],nums[e]};
                        ans.push_back(temp);
                        s++;
                        e--;
                        while(nums[s-1]==nums[s] && s<e)   s++;
                        while(nums[e+1]==nums[e] && s<e)    e--; 
                    }
                    else if(sum<(long long int)target)  s++;
                    else e--;
                }
                int temp=nums[j];
                while(nums[j]==temp && j<nums.size()-2) j++;
                j--;
            }
            int temp=nums[i];
            while(nums[i]==temp && i<nums.size()-3) i++;
            i--;
        }
        //TC O(n^3):
        //SC O(numbrs of unique triplates:)
        return ans;
    } 
};