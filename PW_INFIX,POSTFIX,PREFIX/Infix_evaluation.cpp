
//                                              Warning:
//--->          This code is only competeble with basic 4 pperators:

//The expression which is made by Human readable and understandable is called Infix exp
//The string sontains the different types of operaot;
//;Like we are having the  ep like this "2*50/4-25" the equation is given in the string we have to solve
//This string eqution in the form of string and we have to return the ans:
//And we have to do the infix evaluation to get the ans:
#include<iostream>
#include<stack>
#include<map>
#include<string>
using namespace std;

int solve(int v1,int v2,char ch){
    if(ch=='+')
        return v1+v2;
    if(ch=='*')
        return v1*v2;
    if(ch=='-')
        return v1-v2;
    return v1/v2;
}

int main(){
    //Here we needed 2 stack to solve this problem and our compiler do exetly same thing(to convert the human understable language to machine language):
    //Now we have to under the president of the basic 4 operator
    //D,M (left to right) > A,S ()
    string s="2+6*4/8-3";

    //If the iterator is the number then only push the number into stack:
    //We have to take 2 stack one is for int and another one is char

    //Push the number without thinking if the char is a number
    //Then if the stack is empty push the operator into the stack 
    //But if the stack is having anything then we have to do this thing:
    //If the priyorith of the current operator is strictly greter then the top of the operator then push the element onto the stack;
    //If the priority is >= to the top of the operator then set this current element on the top of the strictly small operaor:
    
    stack<int> num;
    stack<char> op;
    map<char,int> m;
    m['*']=m['/']=2;
    m['+']=m['-']=1;
    cout<<"HELLo"<<endl;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i]))
            num.push(s[i]-48);
        else{
            if( (op.empty()) || m[s[i]]>m[op.top()])
                op.push(s[i]);
            else{
                while( (!op.empty()) && (m[s[i]]<=m[op.top()])){
                    int val2=num.top();
                    num.pop();
                    int val1=num.top();
                    num.pop();
                    num.push(solve(val1,val2,op.top()));
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while(!op.empty()){
        int val2=num.top();
        num.pop();
        int val1=num.top();
        num.pop();
        num.push(solve(val1,val2,op.top()));
        op.pop();
    }
    cout<<"The ans of the given string is:-"<<num.top()<<endl;
    return 0;
}