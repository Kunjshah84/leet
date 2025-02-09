class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int cnt=0ll;
        map<int,int> m;
        m[ (nums.size()-1 - nums[nums.size()-1]) ]++;
        for(int i=nums.size()-2;i>=0;i--){
            cnt+=(m[(i - nums[i])]);
            m[(i-nums[i])]++;
        }
        cout<<cnt;
        return (((nums.size())*(nums.size()-1))/2)-cnt;
    }
};