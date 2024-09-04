#include<iostream>
using namespace std;
int main(){
    //Euplexdivision algo/:
    int x=5,y=10;
    while(x>0 && y>0){
        if(x>y)
            x=x%y;
        else
            y=y%x;
    }
    return 0;
}