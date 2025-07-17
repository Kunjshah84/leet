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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto com=[](ListNode* a,ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(com)> q(com);
        for(auto it:lists)  if(it)  q.push(it);
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(!q.empty()){
            if(!head)   head=tail=q.top();
            else{
                tail->next=q.top();
                tail=tail->next;
            }
            ListNode* temp=q.top();
            q.pop();
            if(temp->next)  q.push(temp->next);
        }
        return head;
    }
};