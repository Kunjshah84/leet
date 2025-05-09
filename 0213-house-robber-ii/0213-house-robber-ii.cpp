class Solution {

    int get(vector<int> &nums,int ind,bool flg,vector<int> &dp1,vector<int> &dp2){
        if(flg && ind==0)   return 0;
        if(ind<0)   return 0;
        if(flg && dp1[ind]!=-1) return dp1[ind];
        if(!flg && dp2[ind]!=-1)    return dp2[ind];
        if(ind==nums.size()-1)  flg=1;
        int sum1=nums[ind]+get(nums,ind-2,flg,dp1,dp2);
        if(ind==nums.size()-1)  flg=0;
        int sum2=get(nums,ind-1,flg,dp1,dp2);
        if(flg) return dp1[ind]=max(sum1,sum2);
        return dp2[ind]=max(sum1,sum2);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        return get(nums,nums.size()-1,0,dp1,dp2);
    }
};