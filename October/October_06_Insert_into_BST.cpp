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
    TreeNode* IntoBSTRecursive(TreeNode* root, TreeNode* curr, int val) {
        if(val>curr->val){
            if(curr->right)
                IntoBSTRecursive(root, curr->right, val);
            else{
                TreeNode* temp= new TreeNode(val);
                curr->right=temp;
                return root;
            }
        }
        else{
            if(curr->left)
                IntoBSTRecursive(root, curr->left, val);
            else{
                TreeNode* temp= new TreeNode(val);
                curr->left=temp;
                return root;
            }
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp= new TreeNode(val);
            return temp;
        }
        TreeNode* curr=root;
        return IntoBSTRecursive(root, curr, val);
    }
};