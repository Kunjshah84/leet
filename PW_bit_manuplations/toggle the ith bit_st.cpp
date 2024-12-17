#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n=13,i=2;
    cout<< (((n>>2)&1) ? (n & ~(1<<i)) : (n | (1<<i)))<<endl;
    cout<<(n ^ (1<<i))<<endl;
    return 0;
}