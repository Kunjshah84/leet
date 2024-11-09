#include<iostream>
#include<string>
using namespace std;
string get(int n){
    if(!n)  return "";
    return get(n/2)+to_string(n%2);
    //Insted of doing the division by the 2 we can use the right shift by the 1 because both are same thing:
}
int get2(string n){
    int mul=1,ans=0;
    for(int i=n.length()-1;i>=0;mul*=2,i--) ans+=((int)n[i]-48)*mul;
    return ans;
}
int get_decimal_with_pw(string n){
    int mul=1,ans=0;
    for(int i=n.length()-1;i>=0;mul<<=1,i--)    ans+=((int)n[i]-48)*mul;
    //for(int i=n.length()-1;i>=0,i--)    ans+=((int)n[i]-48)*(1<<(n-i-1));
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
    //so if we want 2^x then no need to go through the loop and multiplay 2 for the x times;
    //Simply take int vaar=1; and do var<<=x; it
    return 0;
}