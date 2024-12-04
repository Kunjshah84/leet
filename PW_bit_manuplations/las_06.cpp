#include<iostream>
using namespace std;
//Find that how manay bit we have to flip in order to make two numebrs same:--->
int main(){
    cout<<"enter any two number"<<endl;
    int x,y;
    cin>>x>>y;
    int cp=x^y;
    int counter=0;
    while(cp){
        counter++;
        cp&=(cp-1);
    }
    cout<<"Min number of bit flip to make those number same:----"<<counter<<endl;
    return 0;
}