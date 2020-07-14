class Solution {
public:
    int numSquares(int n) {
     
        
        vector<int>dp(n+1,INT_MAX);
        
        dp[0]=0;    //0 perfect squares are required to make a zero
        dp[1]=1;    // 1 perfect square is required to make a one (1 itself)
        
        for(int i=2 ; i<=n ; i++) //looping for numbers 1 onwards
        {
            for(int j=1 ; j<=sqrt(i) ; j++) //to check all possible numbers before i
            {
                
                //minimum numbers reqd is the number (numbers reqd for i-j*j)+1{for j itself}, take min as we are iterating through all possibilities with j<=sqrt(i) and want to take minimum number
                dp[i]=min(dp[i],dp[i-j*j]+1);
                
            }
        }
        
        return dp[n];
    }
    
};
