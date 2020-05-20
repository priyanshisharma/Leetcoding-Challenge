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

    int total_nodes(TreeNode* root)
    {
        if (root == NULL) 
            return 0;
        
        
        return 1 + total_nodes(root->left) + total_nodes(root->right);
        
    }
    int kthSmallest(TreeNode* root, int k) 
    {
    
        int left_nodes = total_nodes(root->left);
        
        if (left_nodes == k-1)
            return root->val;
        else if (left_nodes < k-1) 
            return kthSmallest(root->right, k - left_nodes - 1);
        else
            return kthSmallest(root->left, k);
        
    }
};

// another solution
/*
*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
class Solution {
public:

    int total_nodes(TreeNode* root)
    {
        if (root == NULL) 
            return 0;
        
        
        return 1 + total_nodes(root->left) + total_nodes(root->right);
        
    }
    int kthSmallest(TreeNode* root, int k) 
    {
    
        int left_nodes = total_nodes(root->left);
        
        if (left_nodes == k-1)
            return root->val;
        else if (left_nodes < k-1) 
            return kthSmallest(root->right, k - left_nodes - 1);
        else
            return kthSmallest(root->left, k);
        
    }
};

*/
