class Solution {
public:
  int fun(int i,int j,vector<vector<int>>& grid,vector< vector<int> >&dp)
    {
      if(i<1||j<1)
      {
          return INT_MAX;
      }
        if(dp[i][j]!=-1)
       {
           return dp[i][j];
       }
      if(i==1&&j==1)
      {
          return grid[i-1][j-1];
      }
     
       dp[i][j]=grid[i-1][j-1]+min(fun(i-1,j,grid,dp),fun(i,j-1,grid,dp));
      return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
      int n=grid.size();
        int m=grid[0].size();
        int min=INT_MAX;
        vector< vector<int> >dp(n+1, vector<int>(m+1,-1));
        return fun(n,m,grid,dp);
       
    }
};