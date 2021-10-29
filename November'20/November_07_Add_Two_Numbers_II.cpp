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
        

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    if(l1==NULL)
        return l2;
        
    if(l2==NULL)
        return l1;
        
        int carry = 0;
        

        stack<ListNode*> s1 ;
        stack<ListNode*> s2 ;
        
        while(l1 != NULL) 
        {
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2 != NULL) 
        {
            s2.push(l2);
            l2 = l2->next;
        }
        
        ListNode* result = NULL;
        
        while(!s1.empty() || !s2.empty()) 
        {
            int s1Val, s2Val,sum;

            if(!s1.empty())
            {
                s1Val = s1.top()->val;
                s1.pop();
            }
            else
                s1Val=0;
            
            if(!s2.empty())
            {
                s2Val = s2.top()->val;
                s2.pop();
            }
            else
                s2Val=0;
            
            
            sum = s1Val + s2Val + carry;
            
            if (sum > 9) 
            {
                carry = sum / 10;
                sum = sum % 10;
                
            } else 
            {
                carry = 0;
            }
            
            ListNode* curr = new ListNode(sum);
            if (result == NULL) 
            {
                result = curr;
            } 
            else 
            {
                curr->next = result;
                result = curr;
            }
            
            
        }
        if (carry != 0) 
        {
            ListNode* curr = new ListNode(carry);
            if (result == NULL) 
            {
                result = curr;
            } 
            else 
            {
                curr->next = result;
                result = curr;
            }
        }
        
        return result;
        
        
    
    }
    
};
