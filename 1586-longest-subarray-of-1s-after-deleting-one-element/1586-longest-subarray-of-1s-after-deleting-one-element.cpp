class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,ans=0,cnt_0=0,po;
        while(j<nums.size()){
            cnt_0+=(!nums[j]);
            if(cnt_0>1){
                cnt_0--;
                ans=max(ans,(j-i));
                i=po+1;
            }
            if(!nums[j])    po=j;
            j++;
        }
        ans=max(ans,(j-i));
        return ans-1;
    }
};