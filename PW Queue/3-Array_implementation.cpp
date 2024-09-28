#include<iostream>
using namespace std;

class queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }

    void push(int val){
        if(rear==size /*&& !front*/)//The commented part is in the circuler Q
            cout<<"Not able to push the element:"<<endl;
        else
            arr[rear++]=val;
    }

    int Size(){
        return rear-front;
    }
    void pop(){
        if(Size()==0)//We can call the function of size instead off
            cout<<"The Q is empty you are not able to pop the element:-"<<endl;
        else    front++;
    }
    int top(){
        if(!(Size())){
            cout<<"Empty queue"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(!(Size()))
            return 1;
        return 0;
    }

    int Fornt(){
        if(!(Size())){
            cout<<"The Q is empty:"<<endl;
            return -1;
        }
        return arr[rear-1];
    }   
};

int main(){
    //Implement this function;
    //TOP()
    //push()
    //Pop()
    //Empty()
    //Size()
    //Display()
    //Front
    return 0;
}