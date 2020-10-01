// Runtime: 4 ms, faster than 99.81% of C++ online submissions for Gas Station.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = 0, rem = 0, need = 0,n = gas.size();
        for(int i = 0; i < n; i++){
            if(gas[i] >= cost[i]){
                if(rem < 0){
                    s = i;
                    rem = 0;
                }
            }
            rem += gas[i] - cost[i];
            need += gas[i] - cost[i];
        }
        if(need < 0 or rem < 0)
            return -1;
        return s;
    }
};
