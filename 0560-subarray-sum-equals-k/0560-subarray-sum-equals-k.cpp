class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //It is having the O(n^2) time compleity altho i have used the unordered map
        //Its happens because the in the some of the cases hash collecation happens
        map<int,int> m;
        int cnt=0;
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)  cnt++;
            if(m[sum-k])    cnt+=m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};