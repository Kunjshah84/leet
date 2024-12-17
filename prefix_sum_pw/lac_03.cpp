#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    bool get(vector<int> ans){
        for(int i=0;i<ans.size()-1;i++) if(ans[i]==(ans[ans.size()-1]-ans[i]))  return 1;
        //do some methametical obv yarrr
        //for(int i=0;i<ans.size()-1;i++) if(ans[i]==((ans[ans.size()-1]/2)))  return 1;
        //Now i want to add some more idea that we can also add the binary search once we have created 
        //theprefix sum array:
        return 0;
    }

int main() {
    //check weather he given array can be able to divide into two parts so that the 2 new array have the same 
    //prefix sum:
    vector<int> ans={1,2,3,1,5};
    for(int i=1;i<ans.size();i++)   ans[i]+=ans[i-1];
    cout<<get(ans)<<endl;
    return 0;
}