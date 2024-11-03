#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int main(){
    string s="Kunj R shah";
    cout<<s;
    s.push_back('f');
    cout<<s<<endl;
    s.pop_back();
    cout<<s<<endl;

    //+ operator in string:

    s+="Rajeshkumar";
    cout<<s<<endl;


    //Different usees of reverse functions:
    string t=s;
    reverse(t.begin()+5,t.end()-4);
    cout<<t<<endl;

    //Starting sub string:--->substr(starting ind,length of the substring)

    string p="kunjRshah";
    cout<<p.substr(4)<<endl; 
    cout<<p.substr(1,6)<<endl;


    //To_string()--->Imp string:
    //It converts int to string:
    //We can not directly do the typecasting:
    

    return 0;
}