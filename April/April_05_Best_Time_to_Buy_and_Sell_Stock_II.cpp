class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i=1, prof=0;
        
        while(i<prices.size())
        {
            if(prices[i]>prices[i-1])
                prof += prices[i]-prices[i-1];
                
            i++;
            
        }
        return prof;
        
    }
};
