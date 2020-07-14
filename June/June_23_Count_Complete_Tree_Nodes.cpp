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
    bool IsComplete(TreeNode* root)
    {
        if(root==NULL)
            return true;
        
        if(root->right==NULL)
        {
            if(root->left==NULL)
                return true;
            else if(root->left->right == NULL && root->left->left == NULL)
                return true;
            
            return false;
                
        }
        
        if(root->left==NULL)
        {
            if(root->right==NULL)
                return true;
            else if(root->right->right == NULL && root->right->left == NULL)
                return true;
            
            return false;
                
        }
        
        return IsComplete(root->right)&&IsComplete(root->left);
        
    }
    int countNodes(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        stack<TreeNode*> trav;
        int ctr = 0;
        trav.push(root);
        while(!trav.empty())
        {
            TreeNode* curr = trav.top();
            trav.pop();
            if(curr->left)
                trav.push(curr->left);
            if(curr->right)
                trav.push(curr->right);
            if(IsComplete(curr))
                ctr++;
        }
        
        return ctr;
        
        //return root? 1 + countNodes(root -> left) + countNodes(root -> right): 0;
    }
};
