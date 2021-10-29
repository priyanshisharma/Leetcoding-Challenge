class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int upperCase=0, lowerCase=0;
        
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>='A'&&word[i]<='Z')
                upperCase++;
            else
                lowerCase++;
        }
        if(upperCase==0 || lowerCase==0)
        {
            return true;
        }
        if(upperCase==1 && word[0]>='A'&&word[0]<='Z')
        {
            return true;
        }
        return false;
    }
};