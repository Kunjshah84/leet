class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)   return 1;
        bool sign=1;
        if((dividend<=0 && divisor>0) || (dividend>=0 && divisor<0))   sign=0;
        long d1=abs((long) dividend); 
        long d2=abs((long) divisor); 
        long ans=0;
        while(d1>=d2){
            int cnt=0;
            while(d1 >= (d2<<(cnt+1))) cnt++;
            d1 -= (d2<<cnt);
            ans += (1<<cnt);//Here we are doing the operation with the int 
            //And here the circular operation is happning so it is going to make the 
            //INT_MIN and this will only happen in the case of INT_MIN and the 1 as
            //Divisor:
        }
        if(ans==INT_MIN && sign)    return INT_MAX;
        if(ans==INT_MIN && !sign)    return INT_MIN;
        return (sign) ? ans : (-ans);
    }
};  