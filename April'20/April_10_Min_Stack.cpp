class MinStack {
public:
    /** initialize your data structure here. */
    
    vector<pair<int,int>> v;
    MinStack() {
   
        v.clear();
    }
    
    void push(int x) {
        int min = INT_MAX;
        if(v.size()>0)
        {
           
            min=v[v.size()-1].second;
            min = min<x?min:x;
        }
        else
            min=x;
        
        v.push_back({x,min});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1].first;
    }
    
    int getMin() {
        return v[v.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
