class Solution {
public:
    int nthUglyNumber(int n) {
        
        if(n == 1)  
            return 1;
        
        vector<int> dp(n,0);
        
        dp[0] = 1;
        
        int i2=0,i3=0,i5=0;
        
        int next_multiple_2 = 2*dp[i2];
        int next_multiple_3 = 3*dp[i3];
        int next_multiple_5 = 5*dp[i5];
        
        for(int i=1;i<n;i++)
        {
            
            int insert = min(next_multiple_2,min(next_multiple_3,next_multiple_5));
            dp[i] = insert;
            
            if(insert == next_multiple_2)
            {
                i2++;
                next_multiple_2 = 2*dp[i2];
            }
            
            if(insert == next_multiple_3)
            {
                i3++;
                next_multiple_3 = 3*dp[i3];
            }
            
            if(insert == next_multiple_5){
                i5++;
                next_multiple_5 = 5*dp[i5];
            }
            
        }
        
        return dp[n-1];
    }
};
