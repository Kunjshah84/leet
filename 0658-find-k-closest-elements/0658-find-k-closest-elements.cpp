class Solution {

    pair<int,int> get(int s,int e,int target,vector<int> nums){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]<target)   s=mid+1;
            else e=mid-1;
        }
        return {e,s};
    }

public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        pair <int,int> p=get(0,nums.size()-1,x,nums);
        vector<int> ans;
        while(k && p.first>=0 && p.second<nums.size()){
            if(abs(x-nums[p.first])<=abs(x-nums[p.second])){
                ans.insert(ans.begin(),nums[p.first]);
                p.first--;
            }
            else{
                ans.push_back(nums[p.second]);
                p.second++;
            }
            k--;
        }
        while(k && p.first>=0){
            ans.insert(ans.begin(),nums[p.first]);
            p.first--;
            k--;
        }
        while(k && p.second<nums.size()){
            ans.push_back(nums[p.second]);
            p.second++;
            k--;
        }
        return ans;
    }
};