/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node* trav = head;
        while(trav)
        {
            if (trav->child)
            {
                Node* c_nxt = trav->next;
                
                trav->next = flatten(trav->child);
                if(trav->next)
                {
                    trav->next->prev = trav;
                }
                trav->child = NULL;
                
                while(trav && trav->next)
                    trav = trav->next;
                trav->next = c_nxt;
                if(c_nxt)
                {
                    c_nxt->prev = trav;
                }

            }
            trav = trav->next;
        }
        return head;
    }
};
