class MinStack {
    //Now we are going to solve this question in O(1) time complexity:
public:
    stack<long long> s;
    long long min_val;
    MinStack() {
        min_val=LLONG_MAX;
    }
    
    void push(int val) {
        long long x=(long long)val;
        if(s.size()==0){
            s.push(x);
            min_val=x;
        }
        else if(val>=min_val)   s.push(x);
        else{
            s.push(2*x - min_val);
            min_val=x;
        }
    }
    
    void pop() {
        if(s.top()<min_val)    min_val=2*(min_val)-s.top();
        s.pop();
    }
    
    int top() {
        if(s.top()<min_val) return min_val;
        return s.top();
    }
    
    int getMin() {
        return min_val;
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