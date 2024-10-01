class CustomStack {
    stack<int> s;
    int ms;
public:
    CustomStack(int maxSize) {
        ms=maxSize;
    }
    
    void push(int x) {
        if(s.size()==ms) return ;
        s.push(x);
    }
    
    int pop() {
        if(s.empty())   return -1;
        int val=s.top();
        s.pop();
        return val;
    }
    
    void fun(stack<int> &s,int cnt,int k,int val){
        if(s.empty())   return ;
        int sval=s.top();
        s.pop();
        fun(s,cnt-1,k,val);
        if(cnt<=k)  s.push(sval+val);
        else    s.push(sval);
    }

    void increment(int k, int val) {
        fun(s,s.size(),k,val);
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */