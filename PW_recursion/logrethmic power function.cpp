#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    int get(int x,int n){
        if(!n)  return 1;
        if(n&1) return x*(get(x,(n-1)/2))*(get(x,(n-1)/2));
        else    return (get(x,n/2))*(get(x,n/2));
    }//this will lead you to the more space somplexity and TC funny(find the total numbers of node:)

    int getnegalso(int x, int n) {
    if (n == 0) return 1;  // Base case: x^0 = 1
    if (n < 0) return 1 / get(x, -n);  // Handle negative powers
    int half = get(x, n / 2);  // Compute x^(n/2)
    if (n % 2 == 0)
        return half * half;  // If n is even
    else
        return x * half * half;  // If n is odd
}///There is the same space and TC into then O(log(n--->power))

int main() {
    int x,n;
    cout<<"Enter the value of base and the power:"<<endl;
    cin>>x>>n;
    cout<<get(x,n)<<endl;
    return 0;
}