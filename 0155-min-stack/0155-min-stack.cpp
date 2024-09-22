class MinStack {
public:
    stack<int> s;
    stack<int> helper;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(!helper.empty() && val>helper.top()) helper.push(helper.top());
        else helper.push(val);
    }
    
    void pop() {
        s.pop();
        helper.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */