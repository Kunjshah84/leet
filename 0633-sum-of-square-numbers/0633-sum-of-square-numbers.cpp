class Solution {
public:
    bool judgeSquareSum(int c) {
        if(!c || !(c>>1) || ((int)sqrt(c)*(int)sqrt(c))==c)  return 1;
        int s=0,e=sqrt(c);
        while(s<=e){
            int mid=s+(e-s)/2;
            if((long long int) mid*mid==c)  return 1;
            else if((long long int)mid*mid>c) e=mid-1;
            else break ;  
        }
        while(s<=e){
            if(((long long int)s*s +(long long int) e*e)==c)  return 1;
            else if(((long long int)s*s +(long long int) e*e)>c)    e--;
            else s++;
        }
        return 0;
    }
};