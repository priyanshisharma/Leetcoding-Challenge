class StreamChecker {
	public: 
            // Constructor to insert words in Trie in reverse order and to keep track of length of longest word
	    StreamChecker(vector<string> &words) {
	        for (auto &word: words) {
	            trie.insert_reversed(word); // Inserting word in Trie(in reverse order)
	            if (word.length() > longest_word) // Storing track of length of longest word
	                longest_word = word.length();
	        }
	    }
	    
            // Function to query if for some k >= 1, the last k characters queried (in order from oldest to newest, 
            // including this letter just queried) spell one of the words in the given list
	    bool query(char letter) {
	        queries.insert(queries.begin(), letter); // Inserting letter in front of query vector(Since it's a stream of characters)
	        // Keep in queries only the longest_word last queries, because we don't need the other ones anymore
	        if (queries.size() > longest_word)
	            queries.pop_back();
	        Trie* cur = &trie; // Initialize cur pointer to root of Trie
	        for (auto &ch : queries) {
	            //If we have reached the leaf then we have found desired query
		    if (cur->is_leaf)
		    	return true;
                    // If we have reached end of a word(it has no children for given query) then we have not found desired query
	            if (cur->children[ch -'a'] == NULL)
                    	return false;
                    // Else move to children of current pointer
	            cur = cur->children[ch-'a'];
	        }
	        return cur->is_leaf; // If we have reached end of query then check if our pointer is a leaf or not 
	    }
    
        // Trie Data Structure
	private:    
	    class Trie {
		    public:
                        // Constructor to initialize the variables
		        Trie() {
		            this->is_leaf = false;
		            for(int i = 0; i < 26; i++)
		                this->children[i] = NULL;
		        }
		        
                	// Function to insert words in reverse order
		        void insert_reversed(string word) {
		            Trie* root = this; // Initialize root
                    	    reverse(word.begin(), word.end()); // Reverse the word
		            for(auto &ch : word) {
		                int index = ch - 'a'; // Character index to insert
		                if (root->children[index] == NULL) // If root does not have given child then create one Trie node
		                    root->children[index] = new Trie();
		                root = root->children[index]; // Move to child
		            }
		            root->is_leaf = true; // Mark node as end of word(leaf)
		        }
            	        bool is_leaf; // Bool variable to mark if a given node is end of word(leaf)
		        Trie* children[26]; // Array to store if character index exists in Trie
	    };
    Trie trie;
    vector<char> queries; // Vector to store stream of queries
    int longest_word = 0; // Storing length of longest word in trie
};
