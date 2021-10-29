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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* prev = new TreeNode(-1);
        TreeNode* cur = root;
        prev->left = cur;
        while(cur && cur->val != key){
            prev = cur;
            if(cur->val > key) cur = cur->left;
            else if(cur->val < key) cur = cur->right;
        }
        if(cur == NULL) return root;
        if(cur->left && cur->right){
            TreeNode* tl = cur->left;
            while(tl->right) tl = tl->right;
            tl->right = cur->right;
            if(prev->right == cur) prev->right = cur->left;
            else if(prev->left == cur) prev->left = cur->left;
        }else{
            if(prev->right == cur) prev->right = cur->right ? cur->right: cur->left;
            else if(prev->left == cur) prev->left = cur->right ? cur->right: cur->left;
        }
        root = prev->val == -1? prev->left: root;
        return root;
    }
};