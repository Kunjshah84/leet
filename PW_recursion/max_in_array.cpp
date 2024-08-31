#include<iostream>
#include<math.h>
using namespace std;

int maxval(int arr[],int ind,int n){
    if(ind==n)
        return INT16_MIN;
    return max(arr[ind],maxval(arr,ind+1,10));
}

int main(){
    int arr[10]={-111,2,3,4,5,6,7,8,9,11110};
    cout<<"The max value is:-"<<maxval(arr,0,10)<<endl;
    return 0;
}