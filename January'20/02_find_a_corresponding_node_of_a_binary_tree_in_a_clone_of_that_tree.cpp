/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

    
        stack<TreeNode*> trav;
        trav.push(cloned);
        TreeNode * curr=NULL;
        while(!trav.empty()||curr!=NULL)
        {
            curr = trav.top();
            trav.pop();
            if(curr->val==target->val)
            {
                return curr;
            }
            
            if(curr->left!=NULL)
                trav.push(curr->left);
            
            if(curr->right!=NULL)
                trav.push(curr->right);
        }
        
        return NULL;
        
        
    }
};
