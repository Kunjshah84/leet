class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0,cnt=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                cnt++;
                i++;
                j++;
            }
            else j++;
        }
        return cnt;
    }
};