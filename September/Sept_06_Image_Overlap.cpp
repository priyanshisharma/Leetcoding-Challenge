class Solution {
public:
    
     int shiftOverlap(int xS, int yS, vector<vector<int>>& A, vector<vector<int>>& B) 
     {
        int ctr = 0, b_row = 0;
         
        for (int a_row = yS; a_row < A.size(); ++a_row) 
        {
            int b_col = 0;
            for (int a_col = xS; a_col < A.size(); ++a_col) 
            {
                if (A[a_row][a_col] == 1 && A[a_row][a_col] == B[b_row][b_col])
                    ctr += 1;
                b_col += 1;
            }
            
            b_row += 1;
        }
        return ctr;
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        int res = 0;

        for (int yS = 0; yS < A.size(); ++yS)
        {
            for (int xS = 0; xS < A.size(); ++xS) 
            {
                res = max(res, shiftOverlap(xS, yS, A, B));
                res = max(res, shiftOverlap(xS, yS, B, A));
            }
        }

        return res;
    }
    
};
