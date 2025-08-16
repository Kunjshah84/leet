class Solution {

    void get(vector<int> &target,int i,int j,vector<int> &nums,int sum){
        if(i>j){
            target.push_back(sum);
            return ;
        }
        get(target,i+1,j,nums,sum);
        get(target,i+1,j,nums,nums[i]+sum);
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> x;
        vector<int> y;
        get(x,0,(nums.size())/2,nums,0);
        get(y,((nums.size())/2)+1,nums.size()-1,nums,0);
        sort(y.begin(),y.end());
        int ans=INT_MAX;
        for(auto it:x){
            int i=0,j=y.size()-1;
            while(i<=j){
                int mid=i+(j-i)/2;
                int sum=y[mid]+it;
                if(sum==goal)    return 0;
                ans=min(ans,abs(goal-sum));
                if(sum>goal) j=mid-1;
                else if(sum<goal) i=mid+1;
            }
        }
        return ans;
    }
};