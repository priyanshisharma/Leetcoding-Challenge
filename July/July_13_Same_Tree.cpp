/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p == NULL && q == NULL) 
          return true;
        
        if(p==NULL && q != NULL)
            return false;
        
        if(p != NULL && q==NULL)
            return false;
        
        stack<TreeNode*> p_st, q_st;
        TreeNode* curr_p = p , *curr_q = q; 
        TreeNode* prev_p = NULL, *prev_q = NULL;
        while ((curr_p||!p_st.empty())&&(curr_q||!q_st.empty()))
        {
            
        if(curr_p==NULL && curr_q != NULL)
            return false;
        
        if(curr_p != NULL && curr_q==NULL)
            return false;
            
            while(curr_p)
            {
                p_st.push(curr_p);
                curr_p = curr_p->left;
            }
            while(curr_q)
            {
                q_st.push(curr_q);
                curr_q = curr_q->left;
            }
            
            curr_p = p_st.top(); 
            curr_q = q_st.top(); 
            if(curr_p->val!=curr_q->val)
                return false;
            p_st.pop();
            q_st.pop();
            prev_p = curr_p;
            prev_q = curr_q;
            curr_p = curr_p->right;
            curr_q = curr_q->right;
        } 
        
        return true;
    }
};
