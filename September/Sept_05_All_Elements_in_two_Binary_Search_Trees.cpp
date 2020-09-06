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
     void in_order(TreeNode* root, vector<int> &trav)
    {
        if(root==NULL)
            return;
        
        in_order(root->left,trav);
        trav.push_back(root->val);
        in_order(root->right,trav);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> ino1, ino2;
        
        in_order(root1,ino1);
        in_order(root2,ino2);
        
        vector<int> ret;
        
        int ctr1 = 0, ctr2 = 0;
        
        if(ino1.size()==0)
            return ino2;
        
        if(ino2.size()==0)
            return ino1;
        
        while(ctr1<ino1.size() && ctr2<ino2.size())
        {
            if(ino1[ctr1]<ino2[ctr2])
            {
                ret.push_back(ino1[ctr1++]);
            }
            else
            {
                ret.push_back(ino2[ctr2++]);
            }
        }
        
        while(ctr2<ino2.size())
        {
            ret.push_back(ino2[ctr2++]);
        }
        
        while(ctr1<ino1.size())
        {
            ret.push_back(ino1[ctr1++]);
        }
        
        
        return ret;
    }
};
