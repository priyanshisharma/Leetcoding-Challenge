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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head->next==NULL)
            return head;
        
        ListNode* trav1 = head, *trav2=head->next, *prev=NULL;
        int flag=false;
        
        while(trav1!=NULL && trav2!=NULL)
        {
            while(trav2!=NULL&&(trav1->val==trav2->val))
            {
                trav2=trav2->next;
                flag=true;
            }

            if(flag)
            {
                if(prev==NULL)
                {
                    head = trav2;
                    
                }
                else
                {
                    prev->next = trav2;
                }
                
                trav1 = trav2;
                if(trav2!=NULL)
                    trav2=trav2->next;
                
                flag = false;
            }
            else
            {
                prev = trav1;
                trav1 = trav1->next;
                trav2 = trav2->next;
            }
        }
        
        return head;
        
    }
};
