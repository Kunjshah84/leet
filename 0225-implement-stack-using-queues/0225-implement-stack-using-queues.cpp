class MyStack {
    deque<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push_front(x);
    }
    
    int pop() {
        int val=q.front();
        q.pop_front();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */