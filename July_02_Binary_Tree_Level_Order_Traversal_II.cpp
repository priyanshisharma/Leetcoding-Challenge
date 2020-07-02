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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> res;
        queue<pair<int, TreeNode*>> q;
        
        if(root==NULL)
            return res;
        
        q.push(pair<int, TreeNode*>(0, root));
        
        while(q.size()>0)
        {
            pair<int, TreeNode*> curr=q.front();
            q.pop();
            
            int a = curr.first;
            TreeNode* b = curr.second;
            
            if(a==res.size())
            {
                vector<int> temp;
                res.push_back(temp);
            }
            
            res[res.size()-1].push_back(b->val);
            
            if(b->left!=NULL)
                q.push(pair<int, TreeNode*>(a+1, b->left));
            
            if(b->right!=NULL)
                q.push(pair<int, TreeNode*>(a+1, b->right));
        }
        reverse(res.begin(),res.end());
        return res;
}
        
    
};
