/* Since this is my first time exploring Trie, and might as well be first time for someone reading this too, following are some
links that helped me understand and implement!

https://medium.com/basecs/trying-to-understand-tries-3ec6bede0014
https://iq.opengenus.org/tries/

I hope it helps! Below is the code I submitted!

P.S. I look forward to update and enhance it probably. Not sure about the following code in this repo though, but my 
skillset and knowledge for sure ;) */

class Trie {
public:
    /** Initialize your data structure here. */
    
    bool isLeaf;
    Trie* character[128];
    Trie() {
        
        this->isLeaf = false;
        for (int i = 0; i < 128; i++)
            this->character[i] = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Trie* curr = this;
        
        for(int i=0;i<word.length();i++)
        {
            if(curr->character[word[i]]==NULL)
                curr->character[word[i]] = new Trie();
            
            curr = curr->character[word[i]];    
        }
        
        curr->isLeaf = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        if(this == NULL)
            return false;
        
        Trie* curr = this;
        
        for(int i = 0; i<word.length();i++)
        {
            curr = curr->character[word[i]];
            
            if(curr==NULL)
                return false;
        }
        
        return curr->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        if(this == NULL)
            return false;
        
        Trie* curr = this;
        
        for(int i = 0; i<prefix.length();i++)
        {
            curr = curr->character[prefix[i]];
            
            if(curr==NULL)
                return false;
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
