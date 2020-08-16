class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==0)
            return 0;
        float totProf=0, intermediateProf = 0, buy1 = prices[0], buy2=INT_MAX;
        
        for(int i=0; i<prices.size();i++)
        {
            buy1 = buy1<prices[i]?buy1:prices[i];
            intermediateProf = max(intermediateProf,prices[i]-buy1);
            buy2 = buy2<(prices[i]-intermediateProf)?buy2:(prices[i]-intermediateProf);
            totProf = totProf>(prices[i]-buy2)?totProf:(prices[i]-buy2);
        }
            
        return totProf;
    }
};
