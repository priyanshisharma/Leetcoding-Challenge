class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t);
        while (v[0] < t - 3000)
            v.erase(v.begin());
        return v.size();
    }
};
