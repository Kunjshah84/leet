class FrontMiddleBackQueue {
    list<int> ll;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        ll.push_front(val);
    }
    
    void pushMiddle(int val) {
        auto it=ll.begin();
        advance(it,(ll.size()/2));
        ll.insert(it,val);
    }
    
    void pushBack(int val) {
        ll.push_back(val);
    }
    
    int popFront() {
        if(ll.empty())  return -1;
        int val=ll.front();
        ll.pop_front();
        return val;
    }
    
    int popMiddle() {
        if(ll.empty())  return -1;
        auto it=ll.begin();
        advance(it,(ll.size()-1)/2);
        int val=*it;
        ll.erase(it);
        return val;
    }
    
    int popBack() {
        if(ll.empty())  return -1;
        int val=ll.back();
        ll.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */