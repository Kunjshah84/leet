class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        if(!maxOperations)  return *max_element(nums.begin(),nums.end());
        int s=1,e=*max_element(nums.begin(),nums.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            int op=0;
            for(auto it:nums)   op+=( (it%mid) ? (it/mid) : (it/mid-1));
            if(op>maxOperations)    s=mid+1;
            else    e=mid-1;
        }
        return s;
    }
};