class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,counter=0,max_len=0;
        while(r<nums.size()){
            if(!nums[r])
                counter++;
            while(l<nums.size() && counter>1)
                if(!nums[l++])
                    counter--;
            max_len=max(max_len,r-l);
            r++;
        }
        return max_len;
    }
};