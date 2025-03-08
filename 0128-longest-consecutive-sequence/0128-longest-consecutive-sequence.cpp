class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //first we store all the unique elements into the unordered set
        //then find the strating point by finding that if we had a smaller element there or not?
        //the if we have the smalle one do nothing:
        if(!nums.size())    return 0;
        unordered_set<int> s;
        int ans=1;
        for(auto it:nums)   s.insert(it);
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int cnt=1,var=it;
                while(s.find(var+1)!=s.end()){
                    cnt++;
                    var++;
                }
                ans=max(ans,cnt);
            }
        }  
        return ans; 
    }
};