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
    
    int depth( TreeNode* root, int x, int d)
    {
        if(root==NULL)
            return -1;
        
        if(root->val == x)
            return d;
        
        if(depth(root->left,x,d+1)!=-1)
            return depth(root->left,x,d+1);
        else
            return depth(root->right,x,d+1);
    
    }
    
    bool isCommonParent(TreeNode* root, int x, int y) {
        if (root == NULL) 
        {
            return false;
        }
        
        if (root->left == NULL) 
        {
            return isCommonParent(root->right, x, y);
        }
        if (root->right==NULL) 
        {
            return isCommonParent(root->left, x, y);
        }
        if ((root->left->val == x || root->right->val == x) && 
            (root->left->val == y || root->right->val == y)) 
        {
            return true;
        }
        
        return isCommonParent(root->left, x, y) || isCommonParent(root->right, x, y);
    }
     
    bool isCousins(TreeNode* root, int x, int y) {
        
        int x1, y1;
        x1 = depth(root,x,1);
        y1 = depth(root,y,1);
        
        if(x1==-1||y1==-1)
            return false;
        
        if(x1!=y1)
            return false;
        
        return !(isCommonParent(root , x,y));
               
    }
};
