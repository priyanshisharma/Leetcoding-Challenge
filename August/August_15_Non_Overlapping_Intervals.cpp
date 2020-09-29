class Solution {
public:
    static bool compOp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) 
    {
        if (!v.size()) 
          return 0;
          
        // sorting intervals by end time
        sort(begin(v), end(v), compOp);
        
        // initialising variable for the loop
        int res = 0, lmt = v[0][0];
        
        for (auto e: v) 
        {
            // if the interval finishes before lmt, we increase the counter
            if (e[0] < lmt) 
            {
                res++;
            } else 
            {
                // otherwise we update lmt
                lmt = e[1];
            }
        }
        
        return res;
    }
};
