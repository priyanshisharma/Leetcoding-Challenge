//Code by Prateek Mishra, IIT2018199
/*
This code uses the following ideas:
1. If the sum of gas is less than the sum of cost, then a solution is not possible.
2. Modified kadens algorithm. If sum of array becomes 0 then start your journey from the next index. */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rem = 0, start = 0, sum = 0; //sum is overall sum. rem is the present amout of excess gas left. start is the starting index from where we will start our journey.
        for(int i = 0; i < (int)gas.size(); i++) {
            rem += (gas[i] - cost[i]);
            if(rem < 0) {
                start = i + 1;
                sum += rem;
                rem = 0;
            }
        }
        return (sum + rem < 0) ? -1 : start;
    }
};