class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        if(nums[0]!=nums[1])
            return nums[0];
        
        int beg = 0, end = nums.size()-1,mid;
        while(end>beg&&end-beg!=1)
        {
            
            mid = (end+beg)/2;
         //   cout<<mid<<endl;
            
            if(nums[mid]!= nums[mid+1]&&nums[mid]!=nums[mid-1])
                return nums[mid];
            
            else if(nums[mid]==nums[mid+1])
            {
                if(mid%2 == 0)
                    beg = mid;
                
                else
                    end = mid ;
            }
            else
            {
                if(mid%2 == 0)
                    end = mid ;
                
                else
                    beg = mid;
            }
                
        }
        return nums[nums.size()-1];
    }
};
