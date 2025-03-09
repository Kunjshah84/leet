class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int l=0,r=0;
        int cnt=0;
        while(r<(nums.size())-1){
            r++;
            if(nums[r]==nums[r-1])  l=r;
            if((r-l+1) == k){
                cnt++;
                l++;
            }
        }
        //Now for the circular
        cout<<cnt<<endl;
        r=-1;
        while(l<nums.size()){
            r++;
            if(!r){
                if(nums[r]==nums[nums.size()-1])    break ;
                
            }
            else{
                if(nums[r]==nums[r-1])  break ;
            }
            if((nums.size()-l+r+1)==k){
                cnt++;
                l++;
            }
        }
        return cnt;
    }
};