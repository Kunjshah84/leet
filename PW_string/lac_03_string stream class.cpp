#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
int main(){
    //STRING STREAM CLASS:
    //If we want to access the every words of the stirng which is having the spaces into them then 
    //It is very easy to do that thing by using the stringstream class:

    string name="knuj    is very good boiiii:-";
    //First question:print all the words into different lines:
    stringstream ss(name);
    string stemp;
    while(ss>>stemp)    cout<<stemp<<endl;
    //Question:

    //return the most accuring word into the string:
    string str="Raghav is a maths teacher. He is a DSA mentor as well ";
    //Pirnt the is or a because that 2 word is occuring for the most of the time into the stirng:
    
    stringstream obj(str);
    string temp;
    vector<string> ans;
    while(obj>>temp) ans.push_back(temp);
    sort(ans.begin(),ans.end());
    int fans=-1,cnt=0;
    string fstr="";
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]==ans[i+1]){
            if(fans<cnt) fstr=ans[i];
            cnt++;
        }
        else    cnt=0;
    }
    cout<<"The string wich is occuring for the most of the time is:-"<<endl;
    cout<<fstr<<endl;
    return 0;
}