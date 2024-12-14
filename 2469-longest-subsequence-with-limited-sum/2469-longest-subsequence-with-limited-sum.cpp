class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());
        vector<int> ans(q.size(),0);
        for(int i=1;i<nums.size();i++)  nums[i]+=nums[i-1];//To make the prefix array:
        for(int i=0;i<q.size();i++){
            if(q[i]<nums[0]) ans[i]=0;   
            else{
                //applay the BS:
                int s=0,e=nums.size()-1;
                while(s<=e){
                    int mid=s+(e-s)/2;
                    if(nums[mid]>=q[i]) e=mid-1;
                    else    s=mid+1;
                }
                if(s==nums.size() || nums[s]!=q[i]) s-=1;
                ans[i]=s+1;
            }
        }
        return ans;
    }
};