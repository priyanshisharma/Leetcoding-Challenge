class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> v(costs.size() + 1, vector<int>(366, 0));
                        
        int d_idx = 0;
        
        for (int i = 1; i < 4; i++) {
            d_idx = 0;
            for (int j = 1; j < 366; j++) {
                if (i == 1) {
                    if (days[d_idx] != j) {
                        v[i][j] = v[i][j - 1];                        
                    } else {
                        v[i][j] = v[i][j - 1] + costs[i - 1];
                        if (d_idx + 1 <= days.size() - 1) d_idx++;
                    }                                    
                    continue;
                }    
                
                if (days[d_idx] != j) {
                    if (j == 1) v[i][j] = min(costs[i - 1], v[i - 1][j]);
                    else v[i][j] = min(v[i][j - 1], v[i - 1][j]);
                } else {
                    if (i == 2 && j - 7 >= 1) v[i][j] = min(v[i - 1][j], min(costs[i - 1] + v[i][j - 7], costs[i - 2] + v[i][j - 1]));
                    if (i == 2 && j - 7 < 1) v[i][j] = min(v[i - 1][j], costs[i - 1]);
                    if (i == 3 && j - 30 >= 1) {
                        v[i][j] = min(v[i - 1][j], min(costs[i - 3] + v[i][j - 1] ,min(costs[i - 1] + v[i][j - 30], costs[i - 2] + v[i][j - 7])));
                    }
                    if (i == 3 && j - 30 < 1) v[i][j] = min(v[i - 1][j], costs[i - 1]);
                    
                    if (d_idx + 1 <= days.size() - 1) d_idx++;
                }
            }
        }
        return v[3][days[days.size() - 1]];
    }
};
