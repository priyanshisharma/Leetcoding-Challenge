class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int rows=m;
        int cols = n;
        
        vector<vector<int>> dp(
            rows, 
            vector<int> (cols,0)
        );
        
        dp[0][0]=1;
        
        for(int i=1;i<rows;i++)
        {
                dp[i][0] = dp[i-1][0];
        }
        for(int i=1;i<cols;i++)   
        {
                dp[0][i] = dp[0][i-1];
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                
            }
        }
        
        return dp[rows-1][cols-1];
    }
};
