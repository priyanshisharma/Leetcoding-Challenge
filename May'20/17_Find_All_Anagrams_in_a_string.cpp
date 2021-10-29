class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    
        vector<int> ret;
        
        if(p.size()>s.size())
            return ret;
        
        vector<int> pctr(26,0), findctr(26,0);
            
        for(int i=0;i<p.size();i++)
        {
            pctr[p[i]-'a']++;
        }
        
        for(int i=0;i<p.size();i++)
        {
            findctr[s[i]-'a']++;
        }
        
        for(int i=0;i<=s.size()-p.size();i++)
        {
            if(i!=0)
            {
                findctr[s[i-1]-'a']--;  
                findctr[s[i+p.length()-1]-'a']++; 
            }   
            if(findctr==pctr)
            {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
};
