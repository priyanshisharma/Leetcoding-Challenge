class Solution {
public:
    
    // Aded shorter code for reversing words in given string
    
    string reverseWords(string s) {
        stringstream ss(s);
        string r,ans="";
        
        vector<string> str;
        
        
        while(ss >> r) {
            str.push_back(r);
        }
        
        for(int i = int(str.size())-1; i>=0; --i) {
            ans += str[i];
            ans+=" ";
        }
        ans.pop_back();
        
        return ans;
    }
    
    
    
    
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
