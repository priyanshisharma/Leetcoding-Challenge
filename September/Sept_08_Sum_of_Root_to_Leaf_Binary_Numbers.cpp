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
    int sumRootToLeaf(TreeNode* root) 
    {
       int curr =0, sum=0;
       stack<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<TreeNode*,int> ele = q.top();
            q.pop();
            TreeNode* node = ele.first;
            curr = ele.second;
            
            curr = (curr<<1) | node->val;
                /*
                If you work with decimal representation, the conversion of 1->2 into 12 is easy. 
                You start from curr_number = 1, then shift one register to the left and add the next digit: curr_number = 1 * 10 + 2 = 12.
                
                If you work with binaries 1 -> 1 -> 3, it's the same. 
                You start from curr_number = 1, then shift one register to the left and add the next digit: curr_number = (1 << 1) | 1 = 3.
                
                cur_val << 1 means we're shifting the bits of cur_val to the left by 1 place, which is equivalent to multiplying cur_val by 2 (in base 10). 
                Bitwise OR is used to set a particular bit.
                */
                
                if(node->left==NULL&&node->right==NULL)
                {
                    sum+=curr;
                }
                else
                {
                    if(node->right!=NULL)
                        q.push({node->right, curr});
                    
                    if(node->left != NULL)
                        q.push({node->left, curr});
                }
            
        }
        return sum;
    }
};
