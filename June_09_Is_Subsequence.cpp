class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.size()>t.size())
            return false;
        
        int s_start = 0, t_start = 0;
        
        while(t_start<t.size())
        {
            if(t[t_start]==s[s_start])
                s_start++;
            
            t_start++;
        }
        
        return s_start==s.size();
    }
};
