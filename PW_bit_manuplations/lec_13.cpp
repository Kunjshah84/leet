#include<iostream>
#include<vector>
using namespace std;

    vector<long long int> fact(int n){
        vector<long long int> ans(n+1,1);
        int mod=1000000000+7;
        for(int i=2;i<=n;i++)
            ans[i] = ((i%mod) * (ans[i-1]%mod)) % mod;
        return ans;
    }

int main(){
    //Print the factorial of first 25 number and modulo the result wiht 10^9+7
    cout<<"Here is the ready array of the fact up to the 25th number:-"<<endl;
    //Because i think after the 10th number the fact of the further number is overflow the int limit:
    vector<long long int> ans=fact(25);
    for(int i=0;i<=25;i++)
        cout<<i<<"!  ="<<ans[i]<<endl;
    return 0;
}