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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> trav;
        trav.push(root);
        int ret = 0;
        while(!trav.empty())
        {
            TreeNode* curr = trav.top();
            trav.pop();
            if(curr!=NULL&&curr->left!=NULL)
            {
                if(curr->left->left==NULL&&curr->left->right==NULL)
                    ret+=curr->left->val;
            }
            if(curr!=NULL&&curr->left!=NULL)
                trav.push(curr->left);
            
            if(curr!=NULL&&curr->right!=NULL)
                trav.push(curr->right);
        }
        return ret;
        
    }
};
