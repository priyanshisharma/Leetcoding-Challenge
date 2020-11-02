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
    ListNode* insertionSortList(ListNode* head) {
            
        ListNode* nhead = new ListNode();
        ListNode* curr = head, *prev, *nxt;

        while (curr != NULL) 
        {
            // At each iteration, we insert an element into the resulting list.
            prev = nhead;
            nxt = nhead->next;

            // find the position to insert the current node
            while (nxt != NULL) 
            {
                if (curr->val < nxt->val)
                    break;
                prev = nxt;
                nxt = nxt->next;
            }
            
            ListNode* nextEle = curr->next;
            // insert the current node to the new list
            curr->next = nxt;
            prev->next = curr;

            // moving on to the next iteration
            curr = nextEle;
        }

        return nhead->next;
    }
};
