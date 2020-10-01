public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < cost.size(); i++) {
            cost[i] = gas[i]-cost[i];
        }
        
                 int num = 0, result = 0, tmp = 0; 
        
        for(int i = 0; i < cost.size(); i++) {
            num += cost[i];
            tmp += cost[i];
            if(tmp < 0) {
                result = i+1;
                tmp = 0;
            }
        }
        
        return num >= 0 ? result : -1;
        
 
    }
};
