class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Use the dutch national flag algo:
        //take 3 var which is low mid and high
        //and hypothetically assume that the from the 0 to low-1--->0's
        //and from low to mid-1 there is onlyy--->1's
        //and from the high+1 to size-1--->2's only
        //and the unsorted portation is in between from the mid to high: 
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0)    swap(nums[low++],nums[mid++]);
            else if(nums[mid]==1)   mid++;
            else    swap(nums[high--],nums[mid]);
        }
    }
};