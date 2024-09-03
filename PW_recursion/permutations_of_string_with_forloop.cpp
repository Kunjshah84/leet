#include<iostream>
#include<string>
using namespace std;

void get(string s,string ans){    
    if(s==""){
        cout<<ans;
        cout<<endl;
        return ;    
    }
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        get(left+right,ans+ch); 
    }
}
int main(){
    string s="abc";
    cout<<"Hyyyy"<<endl;
    get(s,"");
    return 0;
}