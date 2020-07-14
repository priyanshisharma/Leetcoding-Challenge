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
    int sumrl = 0;
    void sum(TreeNode* root, int num)
    {
        if(root->left == NULL && root->right == NULL)
        {
            num = num*10 + root->val;
            sumrl+=num;
            return;
        }
        if(root->left)
            sum(root->left, num*10 + root->val);
        
        if(root->right)
            sum(root->right, num*10 + root->val);

    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        sum(root, 0);
        
        return sumrl;
    }
};
