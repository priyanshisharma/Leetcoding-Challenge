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
    int calcPathSum(TreeNode* root, int sum) {
        int ans=0;
        if(root==NULL)
            return 0;
        if(root->val==sum)
            ans++;
        ans+=calcPathSum(root->left,sum-root->val);
        ans+=calcPathSum(root->right,sum-root->val);
        return ans;
        
        
    }
    int pathSum(TreeNode* root,int sum){
        if(root==NULL)
            return 0;
        return pathSum(root->left,sum)+pathSum(root->right,sum)+calcPathSum(root,sum);
    }
};