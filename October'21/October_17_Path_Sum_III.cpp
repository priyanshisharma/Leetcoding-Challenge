class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        
        return checkSum(root, targetSum)+pathSum(root->left, targetSum)+pathSum(root->right, targetSum);
        
    }
    
    int checkSum(TreeNode* root, int targetSum){
        // return targetSum==0?1:0;
        if(root==NULL)
            return 0;
        return (targetSum==root->val?1:0)+checkSum(root->left, targetSum-root->val)+checkSum(root->right, targetSum-root->val);
    }
};

//Time Complexity = O(n*n)
//Space Complexity = O(n)
