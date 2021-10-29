class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        int ctr=0;
        for(unordered_map<char,int> ::iterator itr=mp.begin(); itr!=mp.end(); itr++)
        {
            if(itr->second%2!=0)
                ctr++;
        }
        
        if(ctr==0)
            return s.size();
        
        return s.size()-ctr+1;
    }
};
