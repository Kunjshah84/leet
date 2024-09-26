#include<iostream>
#include<stack>
#include<string>
using namespace std;

int presi(char op){
    if(op=='+' || op=='-')
        return 1;
    return 2;
}

string get(string v1,string v2,char ch){
    string temp="";
    temp+=v1;
    temp+=v2;
    temp+=ch;
    return temp;
}

int main(){
    string s="(7+9)*4/8-3";
    stack<string> num;
    stack<char> op;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i]))
            num.push(to_string(s[i]-48));
        else if( !(s[i]==')') && (s[i]=='(' || op.empty() || presi(s[i])>presi(op.top())))
            op.push(s[i]);
        else{
            if(s[i]==')'){
                while(!(op.top()=='(')){
                    string v2=num.top();
                    num.pop();
                    string v1=num.top();
                    num.pop();
                    num.push(get(v1,v2,op.top()));
                    op.pop();
                }
                op.pop();
            }
            else{
                while(!(op.empty()) && !(op.top()=='(') && presi(s[i])<=presi(op.top())){
                    string v2=num.top();
                    num.pop();
                    string v1=num.top();
                    num.pop();
                    num.push(get(v1,v2,op.top()));
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while(!op.empty()){
        string v2=num.top();
        num.pop();
        string v1=num.top();
        num.pop();
        num.push(get(v1,v2,op.top()));
        op.pop();
    }
    cout<<"The converted postfix expression from infix is:-"<<num.top()<<endl;
    return 0;
}