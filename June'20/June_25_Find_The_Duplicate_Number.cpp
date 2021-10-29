class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        set<int> c;
        set<int>::iterator itr;
        int siz=nums.size(),i,res;
        for(i=0;i<siz;++i)
        {
            itr=c.find(nums[i]);
            if(itr==c.end())
                c.insert(nums[i]);
            else
            {
                res=nums[i];
                break;
            }
        
        }
        return res;
         
        
    }
};
