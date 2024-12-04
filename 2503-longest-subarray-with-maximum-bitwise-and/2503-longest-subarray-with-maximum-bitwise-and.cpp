class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> copy=nums;
        sort(copy.begin(),copy.end());
        int counter=1;
        for(int i=0;i<nums.size();i++){
            int temp=0;
            if(nums[i]==copy[copy.size()-1])
                while(i<nums.size() && nums[i++]==copy[copy.size()-1])
                    temp++;
            if(counter<temp)    counter=temp;
        }
        return counter;
    }
};