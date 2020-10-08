class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int start=i+1;
                int end=nums.size()-1;
                int sum = 0 - nums[i];
                while(start<end)
                {
                    if(nums[start]+nums[end]==sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        ans.push_back(temp);
                        while(start<end && nums[start]==nums[start+1]) start++;
                        while(start<end && nums[end]==nums[end-1]) end--;
                        start++;
                        end--;
                    }
                    else if(nums[start]+nums[end]>sum)
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
                }
            }
        }
        return ans;
    }
};
