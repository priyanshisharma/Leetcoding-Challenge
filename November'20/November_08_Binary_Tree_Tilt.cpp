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
    
    int sum_tree(TreeNode* ele)
    {
        int sum=0;
        stack<TreeNode*> s;
        s.push(ele);
        while(!s.empty())
        {
            ele=s.top();
            s.pop();
            sum+=ele->val;
            if(ele->right)
                s.push(ele->right);
            if(ele->left)
                s.push(ele->left);
        }
        return sum;
    }
    int tiltHelper(TreeNode* ele)
    {
        if(ele==NULL)
            return 0;
        
        if(ele->left==NULL&&ele->right==NULL)
            return 0;
        
        if(ele->left==NULL)
            return abs(sum_tree(ele->right));
        
        if(ele->right==NULL)
            return abs(sum_tree(ele->left));
        
        return abs(sum_tree(ele->left) - sum_tree(ele->right));
    }
    int findTilt(TreeNode* root) {
        
        stack<TreeNode*> lst;
        int res=0;
        lst.push(root);
        while(!lst.empty())
        {
            TreeNode* curr = lst.top();
            res+=tiltHelper(curr);
            //cout<<res<<' '<<tiltHelper(curr)<<endl;
            lst.pop();
            
            if(curr&&curr->left!=NULL)
                lst.push(curr->left);
            
            if(curr&&curr->right!=NULL)
                lst.push(curr->right);
        }
        return res;
        
    }
};
