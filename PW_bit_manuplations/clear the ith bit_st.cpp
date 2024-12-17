#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n=13,i=2;
    cout<<(n-((n&(1<<i)) ? (1<<i) : 0))<<endl;
    cout<<( n & ~(1<<i) )<<endl;
    return 0;
}