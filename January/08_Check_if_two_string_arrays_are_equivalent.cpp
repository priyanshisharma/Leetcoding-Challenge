class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s1, s2;
        
        for(int i=0; i<word1.size(); i++)
        {
            s1.append(word1[i]);
        }
        
        for(int i=0; i<word2.size(); i++)
        {
            s2.append(word2[i]);
        }
        
        return s1==s2;
        
        
    }
};
