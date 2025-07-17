class MedianFinder {

priority_queue<int,vector<int>,greater<int>> min_q; 
priority_queue<int> max_q;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_q.size()==0) max_q.push(num);
        else if(num>=max_q.top())   min_q.push(num);
        else max_q.push(num);
        if(min_q.size()>max_q.size()){
            max_q.push(min_q.top());
            min_q.pop();
        }
        else if(max_q.size()>min_q.size()+1){
            min_q.push(max_q.top());
            max_q.pop();
        }
    }
    
    double findMedian() {
        return (max_q.size()==min_q.size()) ? 
        (double)(max_q.top()+min_q.top())/(double)2: 
        (double)max_q.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */