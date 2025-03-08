class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //use the most voating algo to soleve this question
        //like we know that if the majo is there then it will surealy did not balances 
        //by the other element.....and so on...
        int el=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++){
            if(!cnt){
                el=nums[i];
                cnt=1;
            }
            else (nums[i]==el) ? cnt++ : cnt--;
        }
        return el;
    }
};