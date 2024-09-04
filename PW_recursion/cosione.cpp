#include<iostream>
#include<vector>
using namespace std;

    void get(int pre,int ind,int n,vector<int> ans){
        if(ind==n){
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<endl;
            return ;
        }
        if(pre){
            ans.push_back(0);
            get(0,ind+1,n,ans);
        }
        else if(!pre){
            ans.push_back(0);
            get(0,ind+1,n,ans);
            ans.pop_back();
            ans.push_back(1);
            get(1,ind+1,n,ans);
        }
    }

int main(){
    int n=3;
    cout<<"Hyyyy"<<endl;
    get(1,1,n,{1});
    get(0,1,n,{0});
    return 0;
}