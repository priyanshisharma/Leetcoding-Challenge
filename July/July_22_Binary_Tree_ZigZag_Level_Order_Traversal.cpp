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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        vector<int> temp;
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
       
        queue<TreeNode*> trav;
        bool flag = true;
        trav.push(root);
        trav.push(NULL);
        
        while(trav.size()>1)
        {
            TreeNode* curr = trav.front();
            trav.pop();
           
            if (curr == NULL) 
            { 
                trav.push(NULL);
                if(flag)
                {
                    res.push_back(temp);
                    flag = false;
                }
                else
                {
                    reverse(temp.begin(),temp.end());
                    res.push_back(temp);
                    flag = true;
                }
                temp.clear();
            }  
            else
            {
                if(curr->left!=NULL)
                {
                    trav.push(curr->left);
                }
            if(curr->right!=NULL)
                {
                    trav.push(curr->right);
                }

               temp.push_back(curr->val);
            }
        }
        if(flag)
            {
                res.push_back(temp);
            }
            else
            {
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
            }
        
        return res;
    }
        
    
};
