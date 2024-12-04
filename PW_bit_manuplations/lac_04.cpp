#include<iostream>
using namespace std;
    //To find the least power of 2
    int method_1_PW(int n){
        int ans;
        while(n){
            ans=n;
            n&=(n-1);
        }
        return ans;
    }

    int method_2_PW(int n){
        //This is only valid for the 32 bit binary number:
        n|=(n>>1);
        n|=(n>>2);
        n|=(n>>4);
        n|=(n>>8);
        n|=(n>>16);
        return (n+1)>>1;        
    }

    int method1(int n){
        int ans;
        while(n){
            ans=n;
            n&=(n-1);
        }
        return ans<<=1;
    }

int main(){
    //You are given the number n you have to return the maximam power of 2 that in minnimum to the given
    //Number--->like for n=24 the ans is 16:----->
    int n;
    cout<<"Enter the value of number:-";
    cin>>n;
    cout<<"The value of the biggest smaller power of two:-"<<method_1_PW(n)<<endl;
    cout<<"The value of the biggest smaller power of two by using the method 2:-"<<method_2_PW(n)<<endl;
    //Now if we are having the quesion like we have to find the max power of the 2 then we have two mthod:
    cout<<"The value of the smallest power which is the big then the number by method1:-"<<method1(n)<<endl;
    return 0;
}