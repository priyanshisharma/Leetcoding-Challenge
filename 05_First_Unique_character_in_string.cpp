class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp;
        bool fl;
        for(int i=0;i<s.length();++i)
        {
            mp[s[i]]++;
        }
        int j;
        for(j=0;j<s.size();++j)
        {
            if(mp[s[j]]==1)
            {
                fl=true;
                break;
            }
            else
                fl=false;
        }
        if(fl)
            return j;
        else
            return -1;
        
    }
};
