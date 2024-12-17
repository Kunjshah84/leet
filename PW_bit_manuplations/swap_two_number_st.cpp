#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a=5,b=6;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"The val of a"<<a<<"and "<<b<<endl;
    return 0;
}