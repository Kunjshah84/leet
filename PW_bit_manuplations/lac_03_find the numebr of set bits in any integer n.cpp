#include<iostream>
#include<math.h>
using namespace std;

int get(int n){
    return __builtin_popcount(n);
}

int main(){
    int n;
    cout<<"Enter any number"<<endl;
    cin>>n;
    int counter=0;
    cout<<"The built in function to find the number of set bit is:-"<<__builtin_popcount(n)<<endl;
    while(n){
        if(n&1) counter++; 
        n>>=1;
    }
    //This method will iterate through the number of bits into the decimal number:
    cout<<"The number of set bit is:-"<<counter<<endl;
    //Now we are having the built in method to count the number of set bits:
    cout<<"Logical and less TC consuming method to solve this question"<<endl;
    //In this mehtod the number of iteration is equal to the number of set bit into the decimal number:
    //The algo is called:----->Biran kernigans algo:
    int take_another;
    cout<<"enter the value of the variable for time pass"<<endl;
    cin>>take_another;
    counter=0;
    while(take_another){
        counter++;
        take_another&=(take_another-1);
    }
    cout<<"According to the brians kernigans algo:-"<<counter<<endl;
    cout<<"Here is the implementation of the built in method"<<endl;
    cout<<"The number of set bits into the given number is"<<get(n);
    return 0;
}