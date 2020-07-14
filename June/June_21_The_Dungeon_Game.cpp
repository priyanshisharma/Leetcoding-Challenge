class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n=dungeon.size();
        int m=dungeon[0].size();
        
        int dp[n][m];
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int health=0;
                if(i==n-1&&j==m-1)
                    health=dungeon[i][j];
               else if(i==n-1)
                    health=dungeon[i][j]+dp[i][j+1];
                else if(j==m-1)
                    health=dungeon[i][j]+dp[i+1][j];
                else
                    health=max(dp[i+1][j],dp[i][j+1])+dungeon[i][j];

                dp[i][j]=health>0?0:health;

            }
        }
        
        return abs(dp[0][0])+1;
    }
};
