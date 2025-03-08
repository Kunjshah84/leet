class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)    return 1;
        else if(n==2)   return 5;
        else if(n==3)   return 13;
        long long sum=13ll;
        int var=3;
        for(int i=4;i<=n;i++){
            sum+=((var*2)+6);
            var+=2;
        }
        return sum;
    }
};