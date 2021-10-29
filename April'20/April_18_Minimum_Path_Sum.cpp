class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // using dynamic programming
        int n = grid.size(), m = grid[0].size();
        int dp[n][m];
        
        dp[0][0] = grid[0][0];
        
        // initializing the first col of dp matrix
        for(int i=1;i<n;i++) 
            dp[i][0] = dp[i-1][0] + grid[i][0];
        
         // initializing the first row of dp matrix
        for(int i=1;i<m;i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                // overlapping sub problems
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[n-1][m-1];
    }
};