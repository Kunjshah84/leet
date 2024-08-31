#include<iostream>
using namespace std;

void hanoi(int n,char s,char h,char d){
    if(!n)
        return ;
    hanoi(n-1,s,d,h);//This is going to shift the n-1 plate from s to current helper through destination:)
    cout<<s<<" -> "<<d<<endl;
    hanoi(n-1,h,s,d);//This is going to shift the n-1 plate from current helper to current destination through source:)
}

int main(){
    //We can calculate the min number of move by using pow function:
    //But we have to print the mathod of all the rods:
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}