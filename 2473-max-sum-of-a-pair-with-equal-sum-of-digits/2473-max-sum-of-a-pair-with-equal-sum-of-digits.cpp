class Solution {

    int get(int num){
        int ans=0;
        while(num){
            ans+=(num%10);
            num/=10;
        }
        return ans;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> m;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int temp=get(nums[i]);
            m[temp].push(nums[i]);
        }
        for(auto it:m){
            if(it.second.size()<=1)  continue ;
            int f=it.second.top();
            it.second.pop();
            int s=it.second.top();
            ans=max(ans,f+s);
        }
        return ans;
    }
};