
class Node{
    public: 
    int key,val,cnt;//--->This cnt is to find that the given node is at which level of LRU?
    Node* next;
    Node* pre;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        pre=NULL;
        cnt=1;//--->Why the cnt has initialized with the 1?
        // The ans is that:
        // By defult the cnt or the fr of the node is 1 na!!!!
    }
};

class LRU{
    public: 
    Node* head;
    Node* tail;
    int size;
    LRU(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->pre=head;
        size=0;//--->This size is to controal over the minfr
    }

    void insertAthead(Node* temp){
        Node* nexthead=head->next;
        nexthead->pre=temp;
        temp->next=nexthead;
        head->next=temp;
        temp->pre=head;
        size++;
    }

    void deleteNode(Node* temp){
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
        size--;
    } 
};

class LFUCache {
    unordered_map<int,LRU*>  LruMap;
    unordered_map<int,Node*> keyNode;
    int capacity;
    int currsize;
    int minfr;
public:
    LFUCache(int capacity) {
        // We know that the reapeting part of this code is to updae the LRUFR of the node
        this->capacity=capacity;
        minfr=0;
        currsize=0;
        LruMap.clear();
    }
    
    void UpdateFrequencyLRU(Node* temp){
        keyNode.erase(temp->key);
        LruMap[temp->cnt]->deleteNode(temp);
        if(temp->cnt==minfr && !LruMap[temp->cnt]->size)
            minfr++;
        LRU* newLru=new LRU();
        if(LruMap.find(temp->cnt+1)!=LruMap.end())
            newLru=LruMap[temp->cnt+1];
        temp->cnt++;
        newLru->insertAthead(temp);
        LruMap[temp->cnt]=newLru;
        keyNode[temp->key]=temp;
    }

    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* temp=keyNode[key];
            UpdateFrequencyLRU(temp);
            return temp->val;
        }  
        return -1;

    }
    
    void put(int key, int value) {
        if(!capacity)   return ;
        if(keyNode.find(key)!=keyNode.end()){
            Node* temp=keyNode[key];
            temp->val=value;
            UpdateFrequencyLRU(temp);
        }
        else{
            if(capacity==currsize){
                LRU* tempLRU=LruMap[minfr]; 
                keyNode.erase(tempLRU->tail->pre->key);
                tempLRU->deleteNode(tempLRU->tail->pre);
                currsize--;
            }
            currsize++;
            LRU* newLru=new LRU();
            minfr=1;
            if(LruMap.find(minfr)!=LruMap.end())
                newLru=LruMap[minfr];
            Node* newNode=new Node(key,value);
            newLru->insertAthead(newNode);
            keyNode[key]=newNode;
            LruMap[minfr]=newLru;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */