#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    //First -ve number in every window of size k:
    //Here it is gurenty that the widow is having -ve element into them
    vector<int> ans={2,-3,4,4,-7,-1,4,-2,6};
    //The ans is:---> -3,-3,-7,-7,-7,-1,-2 : final size is ans.size()-k
    int k=3;
    vector<int> fans;
    queue<int> q;
    int j=0;
    while(j<k){
        if(ans[j]<0)    q.push(ans[j]);
        j++;
    }
    fans.push_back(q.front());
    int i=1;
    while(j<ans.size()){
        if(ans[j]<0)    q.push(ans[j]);
        if(ans[i-1]<0)  q.pop();
        fans.push_back(q.front());
        j++;
        i++;
    }
    for(auto it:fans)   cout<<it<<" ";
    //Brute force solution can be done in the O(N*K):--->

    cout<<endl<<"Now here is the solution of PW:"<<endl;
    //Why this method is having the tc of O(n) it is important:

    int n=0;
    int pn=-1;//This is showing the ind of the first -ve number:
    while(n<k){
        if(ans[n]<0)    pn=n;
        n++;
    }
    vector<int> pwans(ans.size()-k+1,0);
    if(pn!=-1)  pwans[0]=ans[pn];
    else    pwans[0]=1;//1 represent that the window is not having the -ve element into this:
    n=k;
    int m=1;
    while(n<ans.size()){
        if(pn>=m)   pwans[m]=ans[pn];
        else{
            pn=-1;
            for(int temp=m;temp<=n;temp++)
                if(ans[temp]<0){
                    pn=temp;
                    break ;
                }
            if(pn!=-1)pwans[m]=ans[pn];
            else pwans[m]=1;
        }  
        n++;
        m++;
    }
    cout<<endl;
    for(auto it:pwans)  cout<<it<<" ";
    //It is important that why the loop is having the TC of O(2n):--->

    return 0;
}