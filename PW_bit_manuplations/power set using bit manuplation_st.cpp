#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> ip={1,2,3};
    vector<vector<int>> ans;
    int n=3;
    for(int i=0;i<(1<<n);i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            // if((i>>(n-j-1))&1)    temp.push_back(ip[j]);
            if(i&(1<<j))  temp.push_back(ip[j]);
        }
        ans.push_back(temp);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    // TC is O(n*(2^n))
    // SC is O(2n*(2^n))--->Not perfect
    //Why we use this bit manuplation method to solve this??
    //Because the method of recursion is taking the extra sapce:
    return 0;
}