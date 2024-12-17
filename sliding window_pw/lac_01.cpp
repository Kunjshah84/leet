#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //find the maximam sum subarray with the fixed size of window
    //formulae ot find the last window :(n-k)--->a banave pachi na na banave
    //approach one:--->
    vector<int> ans={1,2,3,4,5,6,7,8,9};
    int k=3;
    int fsum=0;
    for(int i=0;i<=ans.size()-k;i++){
        int sum=0;
        for(int j=i; j<i+k;j++)  sum+=ans[j];
        fsum=max(fsum,sum);
    }
    cout<<"The max sum in the given size is--->"<<fsum<<endl;
    //This will take the TC of O((n-k+1)*k)
    //Now we are going to take the sliding window:

    int j=0;
    int sum=0;
    fsum=0;
    while(j<k)
        sum+=ans[j++];
    fsum=max(fsum,sum);
    for(int i=1;i<ans.size()-k+1;i++){
        sum+=ans[i+k-1];
        sum-=ans[i-1];
        fsum=max(fsum,sum); 
    }
    cout<<"From the second method:-"<<fsum<<endl;
    //TC of the sw topic O(n-k+1)
    return 0;
}