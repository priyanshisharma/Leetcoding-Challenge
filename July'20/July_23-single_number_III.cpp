class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        vector<int>res;
        for(int i=0; i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(unordered_map<int,int> :: iterator itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second==1)
                res.push_back(itr->first);
        }
        return res;
    }
};
