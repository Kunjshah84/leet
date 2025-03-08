class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cnt=0,es=1,os=0,sum=0;
        for(auto it:arr){
            sum+=it;
            if(sum%2){
                cnt+=(es);
                os++;
            }   
            else{
                cnt+=(os);
                es++;
            }
        cnt=cnt%(1000000007);
        }
        return cnt;
    }
};