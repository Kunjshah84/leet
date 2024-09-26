#include<iostream>
#include<string>
#include<stack>
    int cal(int v1,int v2,char ch){
        if(ch=='+')
        return v1+v2;
        if(ch=='*')
            return v1*v2;
        if(ch=='-')
            return v1-v2;
        return v1/v2;
    }

using namespace std;
int main(){
    string s="-/*+79483";
    // while(s.length()>1){
    //     int v1=char(s[0])-48;
    //     int v2=char(s[1])-48;
    //     char ch=s[3];
    //     s.erase(0,3);
    //     s=cal(v1,v2,ch)+s;
    // }
    stack<int> val;
    for(int i=s.length()-1;i>=0;i--){
        if(isdigit(s[i]))
            val.push(s[i]-48);
        else{
            int v1=val.top();
            val.pop();
            int v2=val.top();
            val.pop();
            val.push(cal(v1,v2,s[i]));
        }
    }
    cout<<"The ans of prefix expression is:-"<<val.top()<<endl;
    return 0;
}