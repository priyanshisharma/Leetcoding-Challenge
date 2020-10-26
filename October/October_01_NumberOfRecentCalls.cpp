class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        //include t in the queue
        q.push(t);
        //eliminates all the time units less than t-3000
        while (!q.empty() && q.front()< (t-3000))
            q.pop();
        
        return q.size();
    }
};
