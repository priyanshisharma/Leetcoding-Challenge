class Solution {
public:
    int singleNumber(vector<int>& nums) {
     
        int res;
        unordered_map<int,int> num_ctr;
        
        for(int i=0;i<nums.size();i++)
          num_ctr[nums[i]]++;
        
        for(int i=0;i<nums.size();i++)
        {
            if(num_ctr[nums[i]]==1)
            {
                res=nums[i];
                break;
            }
        }
        
        return res;
        
    }
};
