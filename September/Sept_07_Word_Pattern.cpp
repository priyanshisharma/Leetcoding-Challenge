class Solution {
public:
    bool wordPattern(string pattern, string str) {
       
        stringstream ss(str);
        vector<string> words; 
        string word;

        while (ss >> word)
            words.push_back(word);      
            
        if (words.size()!=pattern.size())
            return false;
        
        map<char,string> mp;
        map<string,char> mp2;
        for(int i=0; i<words.size(); i++)
        {
            if(mp.find(pattern[i])!=mp.end()||mp2.find(words[i])!=mp2.end())
            {
                
                if(mp[pattern[i]]!=words[i]||mp2[words[i]]!=pattern[i])
                    return false;

            }
            else
            {
                mp[pattern[i]]=words[i];
                mp2[words[i]]=pattern[i];
            }
        }
        
        return true;
        
    }
};
