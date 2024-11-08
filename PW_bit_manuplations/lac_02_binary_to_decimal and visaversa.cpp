#include<iostream>
#include<string>
using namespace std;
string get(int n){
    if(!n)  return "";
    return get(n/2)+to_string(n%2);
}
int get2(string n){
    int mul=1,ans=0;
    for(int i=n.length()-1;i>=0;mul*=2,i--) ans+=((int)n[i]-48)*mul;
    return ans;
}
int get_decimal_with_pw(string n){
    int mul=1,ans=0;
    for(int i=n.length()-1;i>=0;mul<<=1,i--)    ans+=((int)n[i]-48)*mul;
    return ans;
}
int main(){
    //Firsting converting the decimal number to binary:
    cout<<"Enter the decimal number:-"<<endl;
    int n;
    cin>>n;
    string ans=get(n);
    cout<<ans<<endl;
    cout<<"Now we are going to generate the decimal number from binary...."<<endl;
    cout<<get2(ans)<<endl;
    cout<<"Generating the binary string with the PW method:->"<<endl;
    get_decimal_with_pw(ans);
    return 0;
}