#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    int method_1_Pw(int n){
        int ans=n;
        n|=(n>>1);
        n|=(n>>2);
        n|=(n>>4);
        n|=(n>>8);
        n|=(n>>16);
        return ans^n;
    }

    int method_2_Pw(int n){
        //Use the brine method to find just smallest power of 2 and then substrct it with 1:--->
        int copy=n;
        while(n)
            if(n&(n-1)) n&=(n-1);
            else    break ;
        return copy^((n<<1)-1);
    }

int main() {
    //In this question given the number in decimal and flip all the bits into the number;
    int n;
    cout<<"Ente the value of any number:-"<<endl;
    cin>>n;
    //First approach-:
    //make all bits with one in 32 bit binary number:-
    cout<<"The result is:-"<<method_1_Pw(n)<<endl;
    //ohk so the main goal to make all the bits one or we can say that generate the samllest power of 2
    //among all the biggest power of 2 ans then subtract 1 from that number:--->boommmmm
    cout<<"The result is:-"<<method_2_Pw(n)<<endl;
    //We can use the brine algo to solve this question also because we want to find the just smallest pwo of 2:--->

    return 0;
}