class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int num1=0, num2=0,i;
        vector<int> l1, l2;
        for(int ctr1=0; ctr1<version1.size(); ctr1++)
        {
            if(version1[ctr1]=='.')
            {
                l1.push_back(num1);
                num1=0;
            }
            else
            {
                num1 = num1*10 + version1[ctr1]-'0';
            }
            
        }
        
        l1.push_back(num1);
        
        for(int ctr2=0; ctr2<version2.size(); ctr2++)
        {
            if(version2[ctr2]=='.')
            {
                l2.push_back(num2);
                num2=0;
            }
            else
            {
                num2 = num2*10 + version2[ctr2]-'0';
            } 
        }
        l2.push_back(num2);
        
        for(i=0; i<l1.size()&&i<l2.size(); i++)
        {
            
            if(l1[i]<l2[i])
            {
                return -1;
            }
            else if(l1[i]>l2[i])
            {
                return 1;
            }
        }
        
        if(i<l1.size())
        {
            for(int j=i; j<l1.size(); j++)
            {
                if(l1[j]!=0)
                {
                    return i==l2.size();
                }
            }
        }
        
        if(i<l2.size())
        {
            for(int j=i; j<l2.size(); j++)
            {
                cout<<l2[i];
                if(l2[j]!=0)
                {
                    if(i==l1.size())
                        return -1;
                }
            }
            
        }
        
        return 0;
    }
};
