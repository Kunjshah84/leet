class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)    return n;
        int pre=2,prev=1;
        for(int i=3;i<=n;i++){
            pre+=prev;
            prev=pre-prev;
        }
        return pre;
    }
};