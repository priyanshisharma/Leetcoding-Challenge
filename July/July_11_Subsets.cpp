class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> subset;
        res.push_back(subset);
        
        for(int i=0;i<nums.size();i++)
        {
            int sz = res.size();
            for(int j=0;j<sz;j++)
            {
                subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }
        
        return res;
    }
};
