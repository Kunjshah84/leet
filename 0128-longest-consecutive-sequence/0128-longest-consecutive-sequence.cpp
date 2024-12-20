class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())    return 0;
        sort(nums.begin(),nums.end());
        int len=1,cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1)    cnt++;
            else if(nums[i]-nums[i-1]>1){
                len=max(cnt+1,len);
                cnt=0;
            }
        }
        len=max(len,cnt+1);
        return len;
    }
};