class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> duplicate=nums;
        vector<int> ans;
        int a=0,b=0;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]+nums[j]==target){
                a=nums[i];
                b=nums[j];
                break ;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else
                j--;
        }
        int counter=0;
        for(int k=0;k<duplicate.size() && counter!=2;k++){
            if(duplicate[k]==a){
                counter++;
                a=INT_MIN;
                ans.push_back(k);
            }
            else if(duplicate[k]==b){
                counter++;
                b=INT_MIN;
                ans.push_back(k);
            }
        }
        return ans ;
    }
};