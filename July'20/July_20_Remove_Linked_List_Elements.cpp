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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
            return head;
        
        if(head->next==NULL)
        {
            if(head->val==val)
                return NULL;
            return head;
        }
        
        ListNode* np;
        np=head;
        
        while(np!=NULL&&np->next!=NULL)
        {
            if(np->next->val==val)
            {   
                ListNode* temp = np->next;
                np->next=np->next->next;
                delete temp;
            }
            else
                np=np->next;
        }
       while(head!=NULL&&head->val==val)
        {
            head=head->next;
        } 
        
        return head;
    }
};
