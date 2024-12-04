class Solution {
public:
    int minBitFlips(int x, int y) {
        int ans=x^y,counter=0;
        while(ans){
            counter++;
            ans&=(ans-1);
        }
        return counter;
    }
};