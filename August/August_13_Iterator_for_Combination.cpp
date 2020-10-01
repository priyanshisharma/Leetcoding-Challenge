class CombinationIterator {
    vector<string> combinations;
public:
    CombinationIterator(string characters, int combinationLength) {
        string this_ret = "";
        const int n = characters.length();
        for (int i = 0;  i < (1<<n); ++i)
        {
            if (__builtin_popcount(i) == combinationLength)
            {
                for (int j =  n - 1 ; j >=0; --j)
                {
                    if (i&(1<<j)) this_ret.push_back(characters[n-j-1]);
                }
                combinations.push_back(this_ret);
                this_ret.clear();  
            }
        }
    }
    
    string next() {
        auto ret = combinations.back();combinations.pop_back();
        return ret;
    }
    
    bool hasNext() {
        return !combinations.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */