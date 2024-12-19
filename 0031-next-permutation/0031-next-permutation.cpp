class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Now we know that the previous one is striclly having decring sorted part
        //so just change the position of the smallest biggest element with the first sorted one and after swap to make the smallest number rev the part which is previoslly unsorted: 
        if(nums.size()==1)  return ;
        int i=nums.size()-2,j=nums.size()-1;
        while(i>=0 && nums[i]>=nums[i+1])    i--;
        if(i<0){
            reverse(nums.begin(),nums.end());
            return ;
        }
        while(nums[j]<=nums[i])  j--;
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        return ;
    }
};