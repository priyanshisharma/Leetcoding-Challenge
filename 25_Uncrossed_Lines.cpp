class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        

        int arr[A.size() + 1][B.size() + 1];
        
        for (int i = 0; i <= A.size(); i++) 
        {
            for (int j = 0; j <= B.size(); j++) 
            {
                if (i  == 0 || j == 0) 
                {
                    arr[i][j] = 0;
                    continue;
                }
                
                if (A[i - 1] == B[j - 1]) 
                {
                    arr[i][j]  = arr[i - 1][j - 1] + 1;
                } 
                else 
                {
                    int max_val = max(arr[i - 1][j - 1],max(arr[i - 1][j], arr[i][j - 1]));
                    arr[i][j] = max_val;
                }
            }
        }
        
        return arr[A.size()][B.size()];
        
    }
};
