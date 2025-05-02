class Solution {

    void get(vector<vector<int>> &ans,vector<int> &temp,
    vector<int> &fr,vector<int> &nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!fr[i]){
                fr[i]=1;
                temp.push_back(nums[i]);
                get(ans,temp,fr,nums);
                fr[i]=0;
                temp.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // This is the basic approach by using a map
        // TC:O(n!*n)
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> fr(nums.size(),0);
        get(ans,temp,fr,nums);
        return ans;
    }
};