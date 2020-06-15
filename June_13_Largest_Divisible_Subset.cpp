class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if(nums.size()<=1)
            return nums;
        
        unordered_map<int,vector<int>> lis;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            lis[i].push_back(nums[i]);
        }
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]%nums[i]==0&&lis[j].size()>=lis[i].size())
                {
                    lis[i]=lis[j];
                    lis[i].push_back(nums[i]);
                }
            }
        }
        
        int res=nums[0];
        for(unordered_map<int,vector<int>> :: iterator i=lis.begin(); i!=lis.end(); i++)
        {
            if(i->second.size()>lis[res].size())
            {
                res = i->first;
            }
        }

        return lis[res];
        
    }
};
