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
        
    TreeNode* Utilfunc(vector<int>& vec,int min,int max){
            if(vec.size()==0){
                    return nullptr;
            }
            TreeNode* root=nullptr;
            if(vec.front()>min && vec.front()<max){
                    root=new TreeNode(vec.front());
                    vec.erase(vec.begin());
                    root->left=Utilfunc(vec,min,root->val);
                    root->right=Utilfunc(vec,root->val,max);
            }
            return root;
           
                    
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
            return Utilfunc(preorder,INT_MIN,INT_MAX);
        
    }
};
