class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> ref(1000,0);
        for(int i=0; i<trips.size(); i++)
        {
            ref[trips[i][1]]+=trips[i][0];
            ref[trips[i][2]]-=trips[i][0];
            /*for(int j = trips[i][1]-1; j<trips[i][2]-1; j++)
            {
                ref[j]+=trips[i][0];
                if(ref[j]>capacity)
                {
                    return false;
                }
            }*/
        }
        
        int ctr=0;
        for(int i=0; i<1000; i++)
        {
            ctr+=ref[i];
            if(ctr>capacity)
                return false;
        }
        return true;
    }
};
