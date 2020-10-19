/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3481/
*/

class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int> arr, vector<int> curr ,int sum ,int id ,int T){
        if(sum==T){
            ans.push_back(curr);
            return;
        }
        if(sum>T)return;
        for(int i=id;i<arr.size();i++){
            curr.push_back(arr[i]);
            solve(arr,curr,sum+arr[i],i,T);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int T) {
        vector<int>curr;
        solve(arr,curr,0,0,T);
        return ans;
    }
};
