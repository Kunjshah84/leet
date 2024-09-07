#include<iostream>
#include<stack>
using namespace std;

    bool check(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]== '(')
                st.push('(');
            else{
                if(st.empty())
                    return 0;
                else  st.pop();
            }
        }
        if(s.empty())   return 1;
        else    return 0;
    }

int main(){
    string s;
    cin>>s;
    //The string is only having the ( and )
    cout<<"The string is valid or not?"<<check(s);
}