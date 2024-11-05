#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    //We can use the sort function to normally sort the string:
    string s;
    getline(cin,s);
    sort(s.begin(),s.end());
    cout<<s<<endl;
    //Ther is two problems when we directly do the string sort:
    //1->sapces are shifted to the left side of the string:
    //2->if we use the capital latters into out string then we have the issues of sorting:(because the ascci value of the capiatl latter is low)
    //First enter the string kunj  r shah
    //Then enter the stirng Kunj R SHAH
    return 0;
}