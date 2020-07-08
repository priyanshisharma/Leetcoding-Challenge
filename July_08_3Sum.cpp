class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ret;
	
	    if(nums.size()<=2)
            return ret;

	    sort(nums.begin(), nums.end());
	
        int sum;
	
        for( int i=0;i<nums.size()-2;i++)
        {
		    if(nums[i]>0)
                break;
		
            if(i>0&&nums[i-1]==nums[i])
                continue;

		    int beg=i+1, end=nums.size()-1;
            
		    while(beg<end)
            {
			    sum = nums[i] + nums[beg] + nums[end];
			    if(sum==0) 
                {
				    ret.push_back({nums[i],nums[beg],nums[end]});
				    beg++;
				    end--;
				    
                    while(beg<end&&nums[beg]==nums[beg-1])
                        beg++;
                    
				    while(beg<end&&nums[end]==nums[end + 1])
                        end--;
			    }
                else if(sum>0 )
				    end--;
			    else
				    beg++;
		    }
	    }
        
	    return ret;
        
    }
};
