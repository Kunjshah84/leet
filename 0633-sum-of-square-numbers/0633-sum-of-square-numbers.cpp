class Solution {

    bool checkt(int num){
        return floor(sqrt(num))==sqrt(num);
    }

public:
    bool judgeSquareSum(int c) {
        int i=0,j=c;
        while(i<=j){
            if(checkt(i) && checkt(j))    return 1;
            else if(!checkt(j)){
                j=((int)sqrt(j))*((int)sqrt(j));
                //set the values of i   
                i=c-j;
            }
            else{
                i=((int)sqrt(i)+1)*((int)sqrt(i)+1);
                //set the value of the j according to the i
                j=c-i;
            }
        }
        return 0;
    }
};