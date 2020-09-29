class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0||n==1)
            return 1;
        
        int opt[n+1];
        opt[0] = 1;
        opt[1]  = 1;
        for(int i=2;i<=n;i++)
            opt[i] = opt[i-1] + opt[i-2];
        
        return opt[n];
    }
};
