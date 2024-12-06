class Solution {
public:
    long long minimumTime(vector<int>& nums, int totalTrips) {
        long long int s=1;
        long long int e=(long long int)totalTrips*(*max_element(nums.begin(),nums.end()));
        while(s<=e){
            long long int mid=s+(e-s)/2;
            long long int counter=0;
            for(int i=0;i<nums.size();i++) counter+=(mid/nums[i]);
            if(counter>=totalTrips)  e=mid-1;
            else   s=mid+1;
        }
        return s;
    }
};