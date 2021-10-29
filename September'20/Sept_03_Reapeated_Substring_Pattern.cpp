class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int len = s.length();
        bool flag = false;
        if(len<2)
            return false;
        
        if(len%2==0&&s.substr(0,len/2)==s.substr(((len/2) ),len/2))
            return true;
        
        for(int i=1; i<=len/2; i++)
        {
            if(len%i!=0)
                continue;
            
            for(int j=0; j<len-(i);j+=i)
            {
                
                if(s.substr(j,i)!=s.substr(j+i,i))
                {
                    flag=false;
                    break;
                }
                else
                    flag=true;
            }

            if(flag)
                return flag;
        }
        
        return false;
        
    }
};
