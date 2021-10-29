class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        
        vector<vector<int>> ret;
        
        if(nums.size()==1)
        {
            ret.push_back(nums);
            return ret;
        }
        
        if(nums.size()==2)
        {
            ret.push_back(nums);
            vector<int> num2 = nums;
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            if(num2!=nums)
                ret.push_back(nums);
            return ret;
        }
        
        int n = nums.size();
        vector<int> initial_elements,permutation,permuted_elements;
        vector<vector<int>> permuted_vectors;
        unordered_set<int> not_repeated_nums;
        
        for(int i=0;i<n;i++)
        {
            if(not_repeated_nums.find(nums[i])==not_repeated_nums.end())
            {
                initial_elements.push_back(nums[i]);
                not_repeated_nums.insert(nums[i]);
            }
            else
                continue;
            
            permutation = initial_elements;
            for(int k=0;k<n;k++)
            {
                if(k!=i)
                    permuted_elements.push_back(nums[k]);
            }
            
            permuted_vectors = permuteUnique(permuted_elements);
            for(int k=0;k<permuted_vectors.size();k++)
            {
                for(int j=0;j<permuted_vectors[k].size();j++)
                    permutation.push_back(permuted_vectors[k][j]);
                
                ret.push_back(permutation);
                permutation = initial_elements;
            }
            
            initial_elements.clear();
            permutation.clear();
            permuted_elements.clear();
           
        }
        return ret;
        
    }
};
