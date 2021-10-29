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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        if(!head||!head->next){
            return head;
        }
        int length=0;
        while(curr){
            length++;
            curr=curr->next;
        }
        
        for(int i=0;i<(k%length);i++){
            curr=head;
            while(curr->next->next){
                curr=curr->next;
            }
            curr->next->next=head;
            head=curr->next;
            curr->next=NULL;
        }
        return head;
    }
};