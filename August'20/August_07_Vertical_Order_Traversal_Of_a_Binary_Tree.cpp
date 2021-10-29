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
    
    void mapFill(TreeNode *root, int level, int hD, map<int, vector<pair<int, int>>>& mp) {
        //Recursively fill the map of the structure
        // horizontal dist -> {level,val} {level,val}
        // ... and so on
        if(root == NULL)
            return;
        mp[hD].push_back({level, root->val});
        mapFill(root->left, level + 1, hD - 1, mp);
        mapFill(root->right, level + 1, hD + 1, mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, vector<pair<int, int>>> mp;
        mapFill(root, 0, 0, mp); // filled the map
        vector<vector<int>> res;
        
        for(map<int, vector<pair<int, int>>>::iterator itr = mp.begin(); itr!=mp.end(); itr++) //traverse map
        {
            sort(itr->second.begin(), itr->second.end()); //sorted by level
            // level is the first val of each pair in itr->second
            vector<int> temp;
            for(int i=0; i<itr->second.size(); i++) 
            {
                temp.push_back(itr->second[i].second); //Entering values acc to row
            }
            res.push_back(temp); //Enter in Result
            temp.clear();
        }
        
        return res;
    }
};
