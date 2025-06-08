/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m;
        Node* temp=head;
        Node* newl=NULL;
        Node* newt=NULL;
        while(temp){
            Node* t=new Node(temp->val);
            m[temp]=t;
            if(!newl){
                newl=t;
                newt=t;
            }
            else{
                newt->next=t;
                newt=newt->next;
            }
            temp=temp->next;
        }
        Node* fans=newl;
        while(head){
            if(head->random)    newl->random=m[head->random];
            newl=newl->next;
            head=head->next;
        }
        return fans;
    }
};