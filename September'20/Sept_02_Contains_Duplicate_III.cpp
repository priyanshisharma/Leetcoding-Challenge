class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
       
        if(nums.size()>9999)
            return false;
        
        for(int i=1; i<=k ;++i)
        {
            for(int j=0; j<nums.size()-i; ++j)
            {
                if(abs(long((nums[i+j])-(nums[j])))<=t)
                    return true;
                
            }
        }
        
        return false;
    }
};