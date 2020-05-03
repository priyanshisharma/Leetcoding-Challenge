class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<char,int> rn, mg;
        for(int i=0;i<ransomNote.size();i++)
        {
            rn[ransomNote[i]]++;
            mg[ransomNote[i]]=0;
        }
        for(int i=0;i<magazine.size();i++)
        {
            mg[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(rn[ransomNote[i]]>mg[ransomNote[i]])
                return false;
        }
        
        return true;
        
    }
};
