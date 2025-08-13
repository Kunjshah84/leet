class Solution {
public:
    bool isPowerOfThree(int n) {
        // The all of the 4 method is mentioned in the another account:
        return (n>0 && !(1162261467%n) );
    }
};