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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(postorder.size() == 0 || inorder.size() == 0)
        {
            return NULL;
        }
        
        int size = postorder.size();
        int rootVal = postorder[size-1];
        
        TreeNode* root = new TreeNode(rootVal);
        int i = 0;
        for(i; i < size; i++)
        {
            if(inorder[i] == rootVal)
            {
                break;
            }
        }
       
        vector<int> leftIn(inorder.begin(), inorder.begin()+i);
        vector<int> leftPost(postorder.begin(), postorder.begin()+i);
        vector<int> rightIn(inorder.begin()+i+1, inorder.end());
        vector<int> rightPost(postorder.begin()+i, postorder.end()-1);
       
        root->left = buildTree(leftIn, leftPost);
        root->right = buildTree(rightIn, rightPost);
        
        return root;
        
        
    }
};
