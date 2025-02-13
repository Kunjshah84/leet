class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for(auto it:nums)   q.push(it);
        int cnt=0;
        while(!q.empty() && q.top()<k){
            long long one=q.top();
            q.pop();
            if(!q.empty()){
                long long two=q.top();
                q.pop();
                q.push(((2*(min(one,two)))+max(one,two)));
                cnt++;
            }
        }
        return cnt;
    }
};