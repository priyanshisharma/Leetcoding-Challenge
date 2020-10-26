class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> profits;
        //pair of valley and peaks
        stack<pair<int, int>> vps; 
        
        int v;
        int p = -1;
        for (;;) {
            //next valley-peak pair
            for (v = p+1; (v+1 < prices.size()) && (prices[v] >= prices[v+1]); ++v);
            for (p = v  ; (p+1 < prices.size()) && (prices[p] <= prices[p+1]); ++p);
            //both reach end of array
            if (v == p) {
                break;
            }
            
            //add profits
            while ((!vps.empty()) && (prices[v] <= prices[vps.top().first])) {
                profits.push_back(prices[vps.top().second] - prices[vps.top().first]);
                vps.pop();
            }
            while ((!vps.empty()) && (prices[p] >= prices[vps.top().second])) {
                profits.push_back(prices[vps.top().second] - prices[v]);
                v = vps.top().first;
                vps.pop();
            }
            
            // add nre valley-peak pair
            vps.emplace(v, p);
        }
        
        // save all remaining profits
        while (!vps.empty()) {
            profits.push_back(prices[vps.top().second] - prices[vps.top().first]);
            vps.pop();
        }
        
        // Calculate the k highest profits
        int ret;
        if (profits.size() <= k) {
            ret = accumulate(profits.begin(), profits.end(), 0);
        } else {
            nth_element(profits.begin(), profits.end() - k, profits.end());
            ret = accumulate(profits.end() - k, profits.end(), 0);
        }
        return ret;
    }
};
