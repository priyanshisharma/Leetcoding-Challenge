class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        function<int(int)> msbPos = [&](int a){
            int msb_p = -1; 
            while (a) 
            { 
                a = a>>1; 
                msb_p++; 
            } 
            return msb_p; 
        };
        int res = 0; 
        while (m && n) 
        { 
            int msb_p1 = msbPos(m); 
            int msb_p2 = msbPos(n); 

            if (msb_p1 != msb_p2) 
                break; 
            int msb_val =  (1 << msb_p1); 
            res = res + msb_val;
            m -= msb_val; 
            n -= msb_val; 
        } 
        return res; 
    }
};