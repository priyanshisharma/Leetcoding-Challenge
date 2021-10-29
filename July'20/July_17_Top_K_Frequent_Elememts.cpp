class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        vector<int> res;
        priority_queue<pair<int,int>> vals;
        
        // Create map of numbers with frequencies
        for (int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
        }
        
        // Create maxheap, max val chosen according to frequency snd so frequency has been put in position of key , in accordance to {key,value}
        for (unordered_map<int,int> :: iterator  itr=mp.begin();itr!=mp.end();++itr)
        {
            vals.push({itr->second,itr->first});
        }
        
        // Pop top k elements of heap
        for (int i=0;i<k;++i)
        {
            res.push_back(vals.top().second);
            vals.pop();
        }
        
        return res;
    }
};
