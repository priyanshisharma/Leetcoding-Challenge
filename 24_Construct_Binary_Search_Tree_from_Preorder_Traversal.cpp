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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        
        
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* go, *prev;
        go = root;
        
        
        for(int i=1;i<preorder.size();i++)
        {
            go = root;
            while(go != NULL)
            {
                prev = go;
                
                if(go->val>preorder[i])
                {
                    go = go->left;
                }
                else
                {
                    go = go->right;
                }
            }
            if(prev->val<preorder[i])
                {
                    prev->right = new TreeNode(preorder[i]);
                }
            else
                {
                    prev->left = new TreeNode(preorder[i]);
                }
            
        }
        
        return root;
    }
};
