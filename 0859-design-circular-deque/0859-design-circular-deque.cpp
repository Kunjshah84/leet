class MyCircularDeque {
    vector<int> arr;
    int f=0;
    int b=0;
    int s=0;
    int c;
public:
    MyCircularDeque(int k) {
        vector<int> temp(k);
        arr=temp;
        c=k;
    }
    
    bool insertFront(int value) {
        if(isFull())    return 0;
        if(f==0)    f=c-1;
        else    f--;
        arr[f]=value;
        s++;
        return 1;
    }
    
    bool insertLast(int value) {
        if(isFull())    return 0;
        arr[b]=value;
        b++;
        s++;
        if(b==c)    b=0;
        return 1;
    }
    
    bool deleteFront() {
        if(isEmpty())   return 0;
        f++;
        s--;
        if(f==c) f=0;
        return 1;
    }
    
    bool deleteLast() {
        if(isEmpty())   return 0;
        b--;
        s--;
        if(b==-1)   b=c-1;
        return 1;
    }
    
    int getFront() {
        if(isEmpty())   return -1;
        return arr[f];
    }
    
    int getRear() {
        if(isEmpty())   return -1;
        return (b==0) ? arr[c-1] :arr[b-1];
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */