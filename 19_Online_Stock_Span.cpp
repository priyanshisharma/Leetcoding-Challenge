class StockSpanner {
public:
    stack<pair<int,int>> spw;
    StockSpanner() 
    {
        spw.empty();
    }
    
    int next(int price) {
        
        long ctr = 1;
        while(!spw.empty()&&spw.top().first<=price)
        {
            ctr+=spw.top().second;
            spw.pop();

        }
        spw.push(make_pair(price,ctr));
        return ctr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
