class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
      
        int ctr1 = 0, ctr2 = 0;

        vector<int> ret(2,'l');

        for (int i=0; i<nums.size(); i++) 
        {
            if (ret[0] != -1 && ret[0] == nums[i]) 
            {
                ctr1++;
            } 
            else if (ret[1] != -1 && ret[1] == nums[i]) 
            {
                ctr2++;
            } 
            else if (ctr1 == 0) 
            {
                ret[0] = nums[i];
                ctr1++;
            } 
            else if (ctr2 == 0) 
            {
                ret[1] = nums[i];
                ctr2++;
            } 
            else 
            {
                ctr1--;
                ctr2--;
            }
        }

        ctr1 = ctr2 = 0;

        for (int i=0; i<nums.size(); i++) 
        {
            if (ret[0] != 'l' && nums[i] == ret[0]) 
                ctr1++;
            
            if (ret[1] != 'l' && nums[i] == ret[1])
                ctr2++;
        }

        
        int n = nums.size();
        
        if (ctr1 > n/3 && ctr2 > n/3 && ret[0]!=ret[1])
        {
            return ret;
        }
        else if(ctr1 > n/3)
        {
            return {ret[0]};
        }
        else if(ctr2> n/3)
        {
            return {ret[1]};
        }
        return {};
    }
};
