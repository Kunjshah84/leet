class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //I have used the pointer approach 
        //i bscically decide that wher is the first sort part and then i found the
        //next smellest biggest element and put it at the position of the first sorted 
        //element: 
        if(nums.size()==1)  return ;
        int i=nums.size()-2,j=nums.size()-1;
        while(i>=0){
            if(nums[i]<nums[i+1])   break ;
            i--;
        }
        if(i<0){
            sort(nums.begin(),nums.end());
            return ;
        }
        while(i<j){
            if(nums[j]>nums[i]) swap(nums[j],nums[j-1]);
            j--;
        }
        sort(nums.begin()+i+1,nums.end());
        return ;
    }
};