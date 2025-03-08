class NumberContainers {
    unordered_map<int,set<int>> m2;
    unordered_map<int,int> m1; 
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(m1.find(index)!=m1.end() && m1[index]!=number)   m2[m1[index]].erase(index);
        m1[index]=number;
        m2[number].insert(index);
    }
    
    int find(int number) {
        return (m2[number].empty()) ? -1 : *(m2[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */