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
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        
        return mergeSort( head );
    }
    
    ListNode mergeSort( ListNode head )
    {
        if(head == null || head.next == null)
            return head;
        
        ListNode mid = getMid( head );
        ListNode nHead = mid.next;
        mid.next = null;
        
        return merge( mergeSort(head), mergeSort(nHead) );
    }
    
    ListNode merge( ListNode head1, ListNode head2 )
    {
        if(head1 == null || head2 == null)
            return head1 != null ? head1 : head2;
        
        ListNode cur1 = head1;
        ListNode cur2 = head2;
        
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        
        while(cur1 != null && cur2 != null)
        {
            if(cur1.val < cur2.val)
            {
                cur.next = cur1;
                
                cur = cur.next;
                cur1 = cur1.next;
            }
            else
            {
                cur.next = cur2;
                
                cur = cur.next;
                cur2 = cur2.next;
            }
        }
        
        if(cur1 != null)
        {
            cur.next = cur1;
        }
        if(cur2 != null)
        {
            cur.next = cur2;
        }
        return dummy.next;
    }
    
    ListNode getMid(ListNode head)
    {
        if(head == null || head.next == null)
            return head;
        
        ListNode fast = head, slow = head;
        while(fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
}
