class Solution {
public:
    string removeKdigits(string num, int k) {
        
       
        if(num.size()==k)
            return "0";
        
         int ctr = 0;

        for(int i=0;i<num.size()&&ctr!=k;i++)
        {
            if(num[i+1]<num[i])
            {
                num.erase(i,1);
                ctr++;
                i-=2;
                if(i<0)
                {
                    i=-1;
                }
            }   
        }
        
        if(ctr!=k)
        {
            for(int i=0;i<num.size()&&ctr!=k;i++)
        {
            if(num[i+1]==num[i])
            {
                num.erase(i,1);
                ctr++;
                i--;
            }   
        }
        }
        while(num.size()>0&&ctr!=k)
        {
            num.erase(num.size()-1,1);
            ctr++;
        }
        
        while(num[0]=='0')
            num.erase(0,1);
        
        if(num.size()==0)
            return "0";
        
        return num;
       
    }
};
