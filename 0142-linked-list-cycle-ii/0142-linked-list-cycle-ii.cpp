/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> m;
        ListNode* temp=NULL;
        while(head){   
            m[head]++;
            if(m[head]==2){
                temp=head;
                break ;
            }
            head=head->next;
        }
        return temp;
    }
};