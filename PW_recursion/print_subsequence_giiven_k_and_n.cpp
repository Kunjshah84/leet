#include<iostream>
#include<vector>
using namespace std;

void get(int ind,int limit,vector<int> ans,vector<int> que){
    if(ind==que.size()){
        if(ans.size()==limit){
            for(auto it:ans)
                cout<<it<<" ";
        cout<<endl;
        }
        return ;
    }
    if(ans.size() + (que.size()-ind) < limit)//It will incerese the time complexity of the code:
        return ;
    ans.push_back(que[ind]);
    get(ind+1,limit,ans,que);
    ans.pop_back();
    get(ind+1,limit,ans,que);
} 

//We are having first n natural numbers so the duplicates are not allowed:
int main(){
    vector<int> que={1,2,3,4,5};
    get(0,3,{},que);
    return 0;
}