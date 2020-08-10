class Solution {
public:
    int titleToNumber(string s) {
        int i, num=0, j;
        for(i=0;i<s.length();i++)
        {
            num= num*26 + (s[i]-'A') +1;
        }
        return num;
    }
};
