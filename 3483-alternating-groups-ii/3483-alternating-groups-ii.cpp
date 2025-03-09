class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int l=0,r=0,cnt=0;
        while(r<(nums.size()-1)){
            r++;
            if(nums[r]==nums[r-1])  l=r;
            if((r-l+1) == k){
                cnt++;
                l++;
            }
        }
        r=-1;
        while(l<nums.size()){
            r++;
            if(((!r) && (nums[r]==nums[nums.size()-1])) || 
            ((r) && (nums[r]==nums[r-1])))  break ;
            if((nums.size()-l+r+1)==k){
                cnt++;
                l++;
            }
        }
        return cnt;
    }
};