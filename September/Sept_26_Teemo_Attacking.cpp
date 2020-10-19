class Solution {
public:
    int findPoisonedDuration(vector<int>& times, int duration) {
        
        if(times.empty())return 0;

        int res=0;

        for(int i=0;i<times.size()-1;i++)
            res+=min(
                duration,
                times[i+1]-times[i]
            );
            res+=duration;
            return res;
    }
};