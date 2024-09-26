#include<iostream>
#include<stack>
#include<string>
using namespace std;

int presi(char temp){
    if(temp=='+' || temp=='-')
        return 1;
    return 2;
}

int cal(int v1,int v2,char temp){
    if(temp=='+')
        return v1+v2;
    if(temp=='-')
        return v1-v2;
    if(temp=='*')
        return v1*v2;
    return v1/v2;
}

int main(){
    stack<int> num;
    stack<char> op;
    string s="(7+9)*4/8-3";
    cout<<"HELLo"<<endl;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i]))   
            num.push(s[i]-48);
        else if( !(s[i]==')') && (s[i]=='(' || op.empty() || presi(s[i])>presi(op.top())))
            op.push(s[i]);
        else{
            if(s[i]==')'){
                while(op.top()!='('){
                    int v2=num.top();
                    num.pop();
                    int v1=num.top();
                    num.pop();
                    num.push(cal(v1,v2,op.top()));
                    op.pop();
                }
                op.pop();
            }
            else{
                while( !(op.empty()) && !(op.top()=='(') && presi(s[i])<=presi(op.top())){
                    int v2=num.top();
                    num.pop();
                    int v1=num.top();
                    num.pop();
                    num.push(cal(v1,v2,op.top()));
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while(!op.empty()){
        int v2=num.top();
        num.pop();
        int v1=num.top();
        num.pop();
        num.push(cal(v1,v2,op.top()));
        op.pop();
    }
    cout<<"The ans of the infix is:-"<<num.top()<<endl;
    return 0;
}