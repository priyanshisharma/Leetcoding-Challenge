class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b) {
        if(a[0]<b[0])
            return true;
        else if(a[0]==b[0])
            return a[1]>b[1];
        else
            return false;
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return -1;
        // sort the intervals in ascending order of starting values 
        // and if both the values are same sort the end values of the intervals in descending order
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> aux;
        int res = 1;
        aux.push_back(intervals[0][0]);
        aux.push_back(intervals[0][1]);
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][1]>aux[1]) {
                res++;
                aux[0] = intervals[i][0];
                aux[1] = intervals[i][1];
            }
        }
        return res;
    }
};