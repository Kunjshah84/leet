class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j=0;
        for(int i=0;i<2;i++){
            int k=j;
            while(k<nums.size()){
                if(nums[k]==i){
                    swap(nums[j],nums[k]);
                    j++;
                }
                k++;
            }    
        }
    }
};