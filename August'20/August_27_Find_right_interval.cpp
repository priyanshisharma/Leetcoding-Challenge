class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        map<int,int> mp;
        vector<int> ans(size,-1);
        for(int i = 0;i<size;i++){
            mp.insert({intervals[i][0],i});
        }
        for(int i = 0;i<size;i++){
            auto pos = mp.lower_bound(intervals[i][1]);
            if(pos!=mp.end()) ans[i] = pos->second;
        }
        return ans;
    }
};