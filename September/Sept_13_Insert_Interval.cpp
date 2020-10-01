#include<bits/stdc++.h>
#define ll long long int 
class Solution {
public:
    vector<vector<int>> MergeIntervals(vector<vector<int>>& intervals){
        vector<vector<int>>merged_intervals;
        merged_intervals.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            auto last_interval=merged_intervals.back();
            //Condition to check if the intervals need to be merged
            if(last_interval[0]<=intervals[i][0] && last_interval[1]>=intervals[i][0]){
                merged_intervals.pop_back(); // pop the interval and insert the new merged interval
                intervals[i][0]=min(intervals[i][0],last_interval[0]);
                intervals[i][1]=max(intervals[i][1],last_interval[1]);
            }
            merged_intervals.push_back(intervals[i]);
        }
        return merged_intervals;
        
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // TC : O(logn+n+n) lower bound + insert + merge intervals
        int n_intervals=intervals.size();
        if(n_intervals==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int pos=lower_bound(intervals.begin(),intervals.end(),newInterval)-intervals.begin();
        intervals.insert(intervals.begin()+pos,newInterval);
        return MergeIntervals(intervals);
        
    }
};