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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL)
            return NULL;
      //Uncomment this while removing the rest for recursice approach  
      /* if(root->val == val) 
           return root;
        
        if (val < root->val) 
            return searchBST(root->left, val);  
       
        return searchBST(root->right, val);*/
        
       stack<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.top();
            q.pop();
            if(curr->val==val)
                return curr;
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        return NULL;
        
        
       
    }
};
