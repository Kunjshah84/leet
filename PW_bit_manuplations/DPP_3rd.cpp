#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //Find the min numebr to be added to make the number to the power of zero:
    int ans=0,n=7,counter=1;
    while(1)
        if(n&(n-1)){
            ans+=(1<<counter);
            counter++;
        } 
        else    break;
    cout<<"The min number that we have to add to make the given numebr to the power of 2"<<ans<<endl;
    return 0;
}