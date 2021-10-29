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
    int getDecimalValue(ListNode* head) {
       
       int n = -1;
        ListNode *ctr = head;
        while(ctr!=NULL)
        {
            n++;
            ctr=ctr->next;
        }
        ctr=head;
        int res=0;
        while(ctr!=NULL)
        {
            res+=(ctr->val)*(pow(2,n));
            n--;
            ctr=ctr->next;
        }
        return res;
    }
};
