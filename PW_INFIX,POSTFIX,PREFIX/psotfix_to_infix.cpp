#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string s="-/*+79483";
    stack<string> po;
    for(int i=s.length()-1;i>=0;i--){
        if(isdigit(s[i]))
            po.push(to_string(s[i]-48));
        else{
            string s1=po.top();
            po.pop();
            string s2=po.top();
            po.pop();
            string temp="";
            temp+=s1;
            temp+=s[i];
            temp+=s2;
            po.push(temp);
        }
    }
    cout<<"Generated infix exp is:-"<<po.top()<<endl;
    return 0;
}