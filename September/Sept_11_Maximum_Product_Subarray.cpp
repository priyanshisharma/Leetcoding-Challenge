class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int  max_pro=nums[0], loc_max=nums[0], min_pro=nums[0];
        for (int i = 1; i < nums.size(); i++) 
        {
            if(nums[i] < 0)
            {
              /*  
                int temp;
                temp = loc_max;
                loc_max = min_pro;
                min_pro = temp;*/
                swap(loc_max, min_pro);
            }
            
            loc_max = max(nums[i], loc_max * nums[i]);
            min_pro = min(nums[i], min_pro * nums[i]);
            max_pro = max(max_pro, loc_max);
        }
        
        return max_pro;
    }
};
