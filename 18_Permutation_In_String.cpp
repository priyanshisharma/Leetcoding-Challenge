class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    
        if(s1.size()>s2.size())
            return false;
        
        vector<int> s1ctr(26,0), findctr(26,0);
            
        for(int i=0;i<s1.size();i++)
        {
            s1ctr[s1[i]-'a']++;
        }
        
        for(int i=0;i<s1.size();i++)
        {
            findctr[s2[i]-'a']++;
        }
        
        for(int i=0;i<=s2.size()-s1.size();i++)
        {
            if(i!=0)
            {
                findctr[s2[i-1]-'a']--;  
                findctr[s2[i+s1.length()-1]-'a']++; 
            }   
            if(findctr==s1ctr)
            {
                return true;
            }
        }
        
        return false;
           
    }
};
