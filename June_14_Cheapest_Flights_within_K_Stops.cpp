//I believe that is it worthwhile mentioning that I did take some significant external help to solve this within stipulated time. May this enhance my abilities and help me grow in the future and also let you know it is okay to seek help if you really need it.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
         
        if (src == dst) 
            return 0;
        
        unordered_map< int, vector<pair<int, int>> > adjacencyList;
      //  adjacencyList.reserve(n); //reserve function gives minimum capacity
        
        for (int i=0;i<flights.size();i++)
        {
            adjacencyList[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        vector<vector<int>> cheapestCost(n, vector<int>(K+2, INT_MAX));
        cheapestCost[src][0] = 0;
        
        queue<int> destinations;
        destinations.push(src);
        
        int hops = 0;
        
        while (!destinations.empty())
        {
            int sz = destinations.size();
            
            for (int i = 0; i < sz; ++i)
            {
                int currCity = destinations.front();
                destinations.pop();
                
                vector<pair<int, int>> ReachableCities = adjacencyList[currCity];
                
                for (int i=0;i<ReachableCities.size();i++)
                {
                    if (hops == K && ReachableCities[i].first != dst)
                        continue;   //Impossible to reach

                    else if (cheapestCost[currCity][hops] + ReachableCities[i].second < cheapestCost[ReachableCities[i].first][hops+1])
                    {
                        cheapestCost[ReachableCities[i].first][hops+1] = cheapestCost[currCity][hops] + ReachableCities[i].second;
                        
                        if (hops != K)
                            destinations.push(ReachableCities[i].first);
                    }
                }
            }
            
            if (hops == K) 
                break; //Impossible henceforth
            
            ++hops;
        }
        
        int res = INT_MAX;
        
        for (int i=0;i<cheapestCost[dst].size();i++)
        {
            res = min(res, cheapestCost[dst][i]);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
