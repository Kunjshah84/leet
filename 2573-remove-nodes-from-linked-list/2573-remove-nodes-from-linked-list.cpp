/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        stack<ListNode*> s;
        while(head){
            s.push(head);
            head=head->next;
        }
        head=s.top();
        s.pop();
        int comp=head->val;
        while(!s.empty()){
            if(s.top()->val>=head->val){
                s.top()->next=head;
                head=s.top();
            }
            s.pop();
        }
        return head;
    }
};