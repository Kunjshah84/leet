class Solution {
public:
    double myPow(double x, int n) {
        if(!x)  return 0;
        double ba=abs(x);
        if(n==INT_MIN){
            ba*=ba;
            n/=2;
        }
        int po=abs(n);
        double ans=1;
        while(po){
            if(po%2){
                ans*=ba;
                po-=1;
            }
            else{
                ba*=ba;
                po/=2;
            }
        }
        cout<<ans<<endl;
        if(x<0){
            if(n>0) return (n%2) ? -ans : ans ;
            else return (n%2) ? -(1/ans) : (1/ans);
        }
        return (n>0) ? ans : (1/ans);
    }
};