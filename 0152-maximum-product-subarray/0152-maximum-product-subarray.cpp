class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //The brute force approach is to find all of the subarrays:
        //Which might end up taking the O(n^2) TC:
        //Now make the cases:
        //1:--->only have the +ve:
        //2:may have the even -ve:
        //Here 1st and the second cases are same:
        //3:--->have the odd numbers of -ve:(ommite the one of the -ve number)
        //4th:may have the 0 inside the array:
        //We have to make the part of the array whenever we found the 0 inside the 
        //array:
        int ans=INT_MIN,prefix=1,sufix=1;
        for(int i=0;i<nums.size();i++){
            if(!prefix) prefix=1;
            if(!sufix)  sufix=1;
            prefix*=nums[i];
            sufix*=nums[nums.size()-1-i];
            ans=max(ans,max(prefix,sufix));
        }
        return ans;
    }
};