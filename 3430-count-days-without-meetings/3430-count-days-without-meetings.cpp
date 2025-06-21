class Solution {
public:
    int countDays(int days, vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0,pre=0;     
        for(int i=0;i<nums.size();i++){
            if(nums[i][0]>pre) cnt+=(nums[i][0]-pre-1);
            if(pre<nums[i][1])  pre=nums[i][1];
        }
        if(pre<days)    cnt+=(days-pre);
        return cnt;
    }
};