#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class max_heap{
    public:
    int arr[100];
    int size=0;
    max_heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size++;
        int ind = size;
        arr[ind]=val;
        ind--;
        while(ind>1){
            int par=ind/2;
            if(arr[par]<val)    swap(arr[ind],arr[ind+1]);
            else return ;
            ind=par;  
        }
    }

    void deleteroot(int (&arr)[100]){
        if(!size){
            cout<<"Nothing to delete bro"<<endl;
            return ;
        }
        arr[1]=arr[size];
        size--;
        int j=1;
        while(j<=size){
            int lc=(j*2),rc=(j*2)+1;
            if(lc>size || rc>size)    return ;
            if(arr[lc]>arr[rc]){
                swap(arr[lc],arr[j]);
                j=lc;
            }
            else if(arr[rc]>arr[lc]){
                swap(arr[rc],arr[j]);
                j=rc;
            }
            else return ;
        }
    }

    void print(){
        for(auto it:arr)    cout<<it<<" ";
        cout<<endl; 
    }
};

    void heapify(int arr[],int size,int ind){
        int j=ind;
        int lc=ind*2;
        int rc=(ind*2)+1;
        if(lc<size && arr[lc]>arr[j])   j=lc;
        if(rc<size && arr[rc]>arr[j])   j=rc;
        // hear we are going to pass the actual size of the array: 
        if(ind!=j){
            swap(arr[ind],arr[j]);
            heapify(arr,size,j);
        }
    }
//  This code for the max heap is only for the 1 base indexing and here we are going to give the arry as the 0 basea 
//  So we have to change that:

    void heapsort(int (&arr)[],int n){
        for(int i=n-1;i>=1;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i+1 ,0);
        }
    }

int main(){
    // Time complexity inorder to insert the value is O(lo(numsber of nodes)))
    // For the function of the heapify we have to do this
    // for(int i=(size/2);i>0;i++){
        // call the heapify(arr,size,i);
    // } 


    // For the heap sort:
    // And before apply the heap sort we have to convert the array in partially sorted like first in the maxheap(build max heap:)
    // heapsort(arr,size);

    return 0;
}