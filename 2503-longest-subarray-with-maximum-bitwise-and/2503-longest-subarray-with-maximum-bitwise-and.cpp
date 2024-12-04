class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ml=*max_element(nums.begin(),nums.end());
        int ans=0,fans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ml) ans++;
            else{
                fans=max(fans,ans);
                ans=0;
            } 
        }   
        fans=max(fans,ans);
        return fans;
    }
};