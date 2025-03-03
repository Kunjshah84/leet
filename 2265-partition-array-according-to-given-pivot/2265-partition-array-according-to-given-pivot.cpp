class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int cnt=0;
        for(auto it:nums)    
        if(it<pivot)    ans.push_back(it); 
        else if(it==pivot) cnt++;
        while(cnt--)    ans.push_back(pivot);
        for(auto it:nums) if(it>pivot)  ans.push_back(it);
        return ans;  
    }
};