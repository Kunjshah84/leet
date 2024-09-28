class MyCircularQueue {
public:
    int *arr;
    int f=0;
    int b=0;
    int s=0;
    int c;
    MyCircularQueue(int k) {
        arr=new int[k];
        c=k; 
    }
    
    bool enQueue(int value) {
        if(isFull())  return 0;
        arr[b]=value;
        b++;
        s++;
        if(b==c)    b=0;
        return 1;   
    }
    
    bool deQueue() {
        if(isEmpty())   return 0;
        f++;
        s--;
        if(f==c)    f=0;
        return 1;   

    }
    
    int Front() {
        if(isEmpty())   return -1;
        return arr[f];
    }
    
    int Rear() {
        if(isEmpty())   return -1;
        return (!b) ? arr[c-1]: arr[b-1];
        
    }
    
    bool isEmpty() {
        if(!s)  return 1;
        return 0;
    }
    
    bool isFull() {
        if(s==c)    return 1; 
        return 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */