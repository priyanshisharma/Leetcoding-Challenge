class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ret = -1;
        int ctr = 0;
        for(int i=0;i<nums.size();i++) 
        {
            if(ctr == 0) 
            {
                ret = nums[i];
            }
            ctr += (ret == nums[i])?1:-1;
        }
        return ret;
        
        
        /*
        int n = nums.size(), max=0;
        unordered_map<int,int> num;
        
        for(int i=0; i<n;i++)
        {
            if(num[nums[i]]+1>n/2)
            {
                max = nums[i];
            }
            else
                num[nums[i]]++;
        }
        return max;
        */
    }
};
