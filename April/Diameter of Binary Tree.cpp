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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        rec(root, d);
        return d;
    }

    int rec(TreeNode* root, int& d) {
        if (root == NULL) return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d = max(d, ld + rd);
        return max(ld, rd) + 1;
    }
};