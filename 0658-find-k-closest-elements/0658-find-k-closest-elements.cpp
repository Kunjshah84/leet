class Solution {

    int get(int s,int e,int target,vector<int> nums){
            int mid=s+(e-s)/2;
            while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target)   return mid;
            else if(nums[mid]>target)   e=mid-1;
            else s=mid+1;
        }
        if(!s)  return 0;
        else if(s>=nums.size()) return nums.size()-1;
        return e;
    }

public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int ind=get(0,nums.size()-1,x,nums);
        vector<int> ans;
        int i=ind,j=ind+1;
        cout<<ind<<endl;
        while(k && i>=0 && j<nums.size()){
            if(abs(x-nums[j])>=abs(x-nums[i])){
                ans.insert(ans.begin(),nums[i]);
                i--;
            }
            else{
                ans.push_back(nums[j]);
                j++;
            }
            k--;
        }
        while(k && i>=0){
            ans.insert(ans.begin(),nums[i]);
            i--;
            k--;
        }
        while(k && j<nums.size()){
            ans.push_back(nums[j]);
            j++;
            k--;
        }
        return ans;
    }
};