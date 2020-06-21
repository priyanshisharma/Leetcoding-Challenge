//This is a difficult question and definitely broke my streak but very insightful
// Check this out https://www.coursera.org/lecture/cs-algorithms-theory-machines/longest-repeated-substring-hkJBt
//There are so many ways to solve it, check them out too!
//It will definitely take time for a deeper and proper understanding.

class Solution {
public:
    
    string longestDupSubstring(string S) {
        vector<unsigned int> suffix = {};
        char end = 0;
        int ctr = 0;
        
        for(unsigned int i = 0; i < S.size(); ++i )
        {
            if(end == S[i]) 
                ctr++;
            else 
                ctr=0;
            
            if(ctr<5)
                suffix.push_back(i);
            end = S[i];
        }
        
        pair<unsigned int, unsigned int> res={0,0};
        sort(
            suffix.begin(), 
            suffix.end(), 
             [&S, &res](unsigned int i, unsigned int e) 
             { 
                 int s = 0;
                 while( i < S.size() && e < S.size() && S[i] == S[e] )
                { 
                     ++i; 
                     ++e; 
                     ++s; 
                 }
                 if(s>res.second)
                     res = {i-s,s};
                 return S[i]<S[e]; 
             }
             
        );

        if (res.second == 0)
            return "";
        
        return string(S.begin() + res.first, S.begin() + res.first + res.second);
    }
};
