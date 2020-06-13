class RandomizedSet {
public:
    /** Initialize your data structure here. */
    

    
    unordered_map<int,int> loc;   //Since elements should not be repeated set would'be been appropriate
    //to maintain connectivity with vector defined below a map has been chosen.
    vector<int> v;  //to fetch value in O(1) time a vector is apt
    
    RandomizedSet() {
        loc.clear();
        v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(loc.find(val)!= loc.end())
            return false;
        
        v.push_back(val);
        int end = v.size()-1;
        loc.insert({val,end});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        if(loc.find(val) == loc.end())
            return false;

        int pos = loc[val];
        int end = v[v.size()-1];
        
        v[pos] = end;
        v.pop_back();
        
        loc[end] = pos;            
        loc.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int i = rand() % v.size();
       return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
