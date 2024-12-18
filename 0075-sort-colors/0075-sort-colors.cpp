class Solution {
public:
    void sortColors(vector<int>& nums) {
        //here i am using the three pointer approach:
        //because here i have to arrange the 3 elements:
        int v0=0,v1=0,var=0;
        while(var<nums.size()){
            if(nums[v0]==nums[v1]==0 && v0==v1){
                v0++;
                v1++;
            }
            else if(nums[v1]==1)    v1++;
            else if(nums[var]==1){
                swap(nums[v1],nums[var]);
                v1++;
            }
            else if(nums[var]==0){
                if(v0!=v1){
                    swap(nums[v0],nums[var]);
                    swap(nums[var],nums[v1]);
                }
                else    swap(nums[v0],nums[var]);
                v0++;
                v1++;
            }
            var++;
        }
    }
};