class Solution {
public:
    int lengthOfLastWord(string s) {
        
        stringstream str(s);
        
        string word;
        while(str>>word);
        
        return word.length();
    }
};
