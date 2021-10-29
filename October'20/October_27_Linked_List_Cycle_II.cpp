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
    ListNode* sptr, *fptr;
    bool hasCycle(ListNode *head) {
        
        if(head==NULL)
    {
        return false;
    }

    
    sptr=fptr=head;

    while(fptr!=NULL&&fptr->next!=NULL){
        sptr=sptr->next;
        fptr=fptr->next->next;
        if(sptr==fptr)
        {
            return true;
        }
    }

    return false;

    }       
    
    ListNode *detectCycle(ListNode *head) {
        
       if(head==NULL||head->next==NULL)
           return NULL;
 
    bool fl = hasCycle(head);
        if(fl)
        {
            ListNode*f;
            f=head;
            while(f!=sptr)
            {
                f=f->next;
                sptr=sptr->next;
            }
            return f;
        }
        return NULL;
    }
};
