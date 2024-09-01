#include<iostream>
#include<string>
using namespace std;

    void get(string ans,string mstr){
        if(mstr==" "){
            cout<<ans<<endl;
            return ;
        }
        char ch=mstr[0];
        get(ans,mstr.substr(1));
        get(ans+ch,mstr.substr(1));
    }

int main(){
    string str="abc";
    get("",str);
    return 0;
}
