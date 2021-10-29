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
    ListNode* oddEvenList(ListNode* head) {
        
       if(head==NULL)
           return NULL;
        ListNode* o, *e, *save;
        save = e = head->next;
        o = head;
        e = head->next;
        while(o!=NULL && e!=NULL)
        {
            o->next = e->next;
            if(o->next!=NULL)
                e->next = o->next->next;
            else
            {
                e->next = NULL;
                o->next = save;
                break;
            }
            o = o->next;
            e = e->next;
        }
        if(e==NULL)
        {
            o->next = save;
        }
        return head;
        
       
        
    }
};
