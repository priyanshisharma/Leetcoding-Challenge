class WordDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<string>> a, b;
    WordDictionary() {
        a = b; //initialise to empty
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        a[word.size()].push_back(word); 
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        vector<string> c=a[word.size()];
        bool flag=false;
        for(int i=0;i<c.size();i++)
        {
            for(int j=0; j<word.size();j++)
            {
                if(word[j]=='.')
                {
                    flag = true;
                    continue;
                }
                else if(c[i][j]!=word[j])
                {
                    flag = false;
                    break;
                }
                else
                {
                    flag = true;
                }
            }
            
            if(flag)
                return flag;
            
        }
        return flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
