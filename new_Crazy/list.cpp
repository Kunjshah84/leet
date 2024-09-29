#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main(){
    vector<int> a{1,2,3};
    list<int> ll(a.begin(),a.end());
    for(auto it=ll.begin();it!=ll.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}