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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            
            if(curr->left!=NULL)
                q.push(curr->left);
            
            if(curr->right!=NULL)
                q.push(curr->right);

        }
        
        return root;
        
    }
};

/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL)
            return NULL;
        
        TreeNode* r = invertTree(root->right);
        TreeNode *l = invertTree(root->left);
        
        root->left = r;
        root->right = l;
        
        return root;
        
    }
};
*/

            
            
