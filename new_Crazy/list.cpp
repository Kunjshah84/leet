#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main(){
    //This list Is a by deafult representation of dobly link list and we are able to push and pop the element at const time complexity:
    vector<int> a{1,2,3};
    list<int> ll(a.begin(),a.end());//We can initialize our list with the range of the element:
    //list.begin() return's a starting iterator:
    for(auto it=ll.begin();it!=ll.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //Basic operation into list:
    //1--->Push_front():
    ll.push_front(0);
    ll.push_back(4);
    //If we want to insert the element at specific position then we can do that:
    auto it=ll.begin();
    ll.insert(it,-1);//Insert -1 befort first element:
    //Erase():-->Delete specific node of Dll at the given iterator:
    //Empty():--->It check's that the list is empty or not?
    cout<<"Weather the list is empty?:-"<<ll.empty()<<endl;
    //Size():--->Return number of nodes in LL:
    cout<<"The size of List is:-"<<ll.size()<<endl;
    
    return 0;
}