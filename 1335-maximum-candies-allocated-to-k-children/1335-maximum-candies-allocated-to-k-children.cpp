class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int s=1,e=*max_element(nums.begin(),nums.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            long long child=0;
            for(auto it:nums){
                child+=(it/mid);
                if(child>k)    break ;
            }
            if(child>=k)    s=mid+1;//Chocolate vadharo:
            else e=mid-1;
        }
        return e;
    }
};