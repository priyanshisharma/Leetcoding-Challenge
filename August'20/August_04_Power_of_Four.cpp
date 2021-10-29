class Solution {
public:
    bool isPowerOfFour(int num) {
        
        while(num>16)
        {
            //if not divisible by four at any point, return
            if((num%100)%4!=0)
                break;
            
            //Keep dividing by 4
            num/=4;
            
        }   
        
        //base case
        if(num==16||num==4||num==1)
            return true;
        
        return false;
        
    }
};
