class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 31; 
        //power is 31, for num at location i new location is 31-i , index starts from 0 {2 to the power 0 is the first position}
        
        while (n != 0) 
        {
          ret += (n & 1) << power;
            // n&1 works like n%2 <<power moves it to 31 spaces inititally
          n = n >> 1;
            // n>>1 works like n/2
          power -= 1;
            // power gets changed to 31-i for every i
        }
        
        return ret;
    }
};
