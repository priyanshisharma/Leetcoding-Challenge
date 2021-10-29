class Solution {
public:
    string strrev(string g)
    {
        string d;
        for(int i = g.size() -1; i>=0;i--)
            d.push_back(g[i]);
        return d;
    }
    string reverseWords(string s) {
        
      
        string word,ret;
        if(s==word)
            return s;
        int i=0;
        while(s[i]==' ')
        {
            s.erase(i,1);
        }
        if(s==word)
            return s;
        i = s.size()-1;
        while(s[i]==' ')
        {
            s.erase(i,1);
            i--;
        }
        
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==' ')
            {
                if(word.size()>0)
                {
                   word = strrev(word);
                ret.append(word);
                ret.push_back(' ');
                
                word.clear(); 
                } 
            }
            else
                word.push_back(s[i]);
        }
        
        word = strrev(word);
        ret.append(word);
        
        return ret;  
    }
};
