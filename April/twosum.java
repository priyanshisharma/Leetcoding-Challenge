class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            if(root->right==NULL){
                return root->left;
            }
            TreeNode* tmp = root->right;
            while(tmp->left){
                tmp = tmp->left;
            }
            tmp->left=root->left;
            return root->right;
        }
        if(root->val>key)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
    }
};