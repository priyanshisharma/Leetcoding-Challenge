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
    
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int res = 1;
        queue<pair<TreeNode*, int>> vals;
        vals.push({root, 0});
        while(!vals.empty())
        { 
            int beg = vals.front().second;
            int end = vals.back().second;
            
            res = max(res, end-beg+1);
            
            int sz = vals.size();
            for(int i = 0; i < sz; ++i)
            {
                pair<TreeNode*, int> curr = vals.front();
                vals.pop();
                
                if(curr.first->left!=NULL) 
                {   
                    vals.push({curr.first->left, ((2*(curr.second-beg))+1)});
                }
                
                if(curr.first->right!=NULL) 
                    vals.push({curr.first->right, ((2*(curr.second-beg))+2)});
            }
            
        }
        return res;
    }
};
