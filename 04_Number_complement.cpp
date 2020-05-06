class Solution {
public:
    int findComplement(int num) {
        
        long n = 2;
        while(n<=num)
            n*=2;
        
        
        int ret;
        ret = n - num -1;
        return ret;
        
    }
};
