class Solution {
public:
    string validIPAddress(string IP) {
        
        int ctr_dot=0, ctr_colon=0;
        for(int i=0;i<IP.size();i++)
        {
            if(IP[i]=='.')
                ctr_dot++;
            
            if(IP[i]==':')
                ctr_colon++;
        }
        
        if(ctr_dot==3)
        {
            if(IP[IP.size()-1]=='.')
                return "Neither";
            if(IP[0]=='.')
                return "Neither";
            
            int pos = -1,i;
            for(i=0;i<IP.size();i++)
            {
                if(IP[i]=='.')
                {
                    if(IP[i+1]=='.')
                        return "Neither";
                    
                    if(i-pos>4)
                        return "Neither";
                    else
                    {
                        if(i-pos>=3)
                        {
                            if(IP[pos+1]=='0')
                                return "Neither";
                        }
                        if(i-pos == 4)
                        {
                            string check;
                            check.push_back(IP[pos+1]);
                            check.push_back(IP[pos+2]);
                            check.push_back(IP[pos+3]);
                            int num = stoi(check);
                            if(num>255)
                                return "Neither";
                        }
                        pos=i;
                    }
                }
                else if(!(IP[i]>='0'&&IP[i]<='9'))
                    return "Neither";
                
            }
            if(i-pos>=3)
            {
                if(IP[pos+1]=='0')
                    return "Neither";
            }
            if(i-pos == 4)
            {
                string check;
                check.push_back(IP[pos+1]);
                check.push_back(IP[pos+2]);
                check.push_back(IP[pos+3]);
                int num = stoi(check);
                if(num>255)
                    return "Neither";
            }
            return "IPv4";
        }
        if(ctr_colon==7)
        {
            if(IP[IP.size()-1]==':')
                return "Neither";
            if(IP[0]==':')
                return "Neither";
            
            int pos = -1,i;
            for(i=0;i<IP.size();i++)
            {
                if(IP[i]==':')
                {
                    if(IP[i+1]==':')
                        return "Neither";
                    
                    if(i-pos>5)
                        return "Neither";
                    else
                    {
                        pos=i;
                    }
                }
                else if(!((IP[i]>='0'&&IP[i]<='9')||(IP[i]>='a'&&IP[i]<='f')||(IP[i]>='A'&&IP[i]<='F')))
                    return "Neither";
                
            }
            if(i-pos>5)
                return "Neither";
            
            return "IPv6";
            
            
        }
        return "Neither";
    }
};
