class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool f=false;
        for(int i=0 ; i<digits.size();i++)
        {
            if(digits[i]==9)
                f = true;
            else
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            vector<int> c;
            c.push_back(1);
            for(int i=0 ; i<digits.size();i++)
                c.push_back(0);
            return c;
        }
        
        int num,carry,i;
        num=1;
        carry=1;
        i=digits.size()-1;
        while(carry!=0)
        {
           num=digits[i]+carry;
            carry=num/10;
            num=num%10;
            digits[i]=num;
            i--;
            
        }
        return digits;
    }
};
