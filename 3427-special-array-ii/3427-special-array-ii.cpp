class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        vector<bool> ans(q.size(),1);
        if(nums.size()==1)  return ans;
        vector<int> temp(nums.size(),0);
        int sum=0;
        for(int i=1;i<nums.size()-1;i++){
            if( (nums[i]%2)==nums[i-1]%2 || (nums[i]%2)==nums[i+1]%2 )
                sum++;
            temp[i]=sum;
        }
        if(nums[nums.size()-1]%2 == nums[nums.size()-2]%2)
            temp[nums.size()-1]=sum+1;
        else temp[nums.size()-1]=sum;
        for(auto it:temp)   cout<<it<<endl;
        for(int i=0;i<q.size();i++){
            if(q[i][0]==q[i][1])
                ans[i]=1;
            else if((nums[q[i][0]]%2)==nums[q[i][0]+1]%2 
            || nums[q[i][1]]%2==nums[q[i][1]-1]%2)
                ans[i]=0;
            else if(q[i][1]-q[i][0]!=1 && temp[q[i][1]-1]-temp[q[i][0]+1]!=0)
                ans[i]=0;
            else 
                ans[i]=1;
        }
        return ans;
    }
};