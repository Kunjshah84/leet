class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int ele1,ele2;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=ele2){
                ele1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i]!=ele1){
                ele2=nums[i];
                cnt2++;
            }
            else if(nums[i]==ele1)  cnt1++;
            else if(nums[i]==ele2)  cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(auto it:nums){
            if(it==ele1)    cnt1++;
            else if(it==ele2)   cnt2++;
        }
        int minreq=(nums.size()/3+1);
        if(cnt1>=minreq && cnt2>=minreq) return {ele1,ele2};
        else if(cnt1>=minreq)   return {ele1};
        else if(cnt2>=minreq) return {ele2}; 
        return {};
    }
};