class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int ctr=0,max_=0;
        
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int i=0;i<nums.size();i++)
        {
            ctr = ctr + (nums[i]==1?1:-1);
            
            if(mp.find(ctr)!=mp.end())
                max_ = max(max_ , i - mp[ctr]);
            
            else
                mp.insert({ctr,i});
            
        }

        return max_;
    
    }
};
