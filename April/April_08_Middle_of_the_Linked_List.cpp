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
    
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *fptr , *sptr;
        fptr=head;
        sptr=head;
        
        while( fptr!=NULL&&fptr->next!=NULL )
        {
            fptr=fptr->next->next;
            sptr=sptr->next;
        }
      
            return sptr;
        
    }
};
