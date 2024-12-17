#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n=13,i=2;
    if(n&(1<<i))    cout<<"yes"<<endl;
    else cout<<"No"<<endl;
    if(n>>i&1)    cout<<"yes"<<endl;
    cout<<"No"<<endl;
    return 0;
}